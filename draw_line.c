/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:30:03 by magrab            #+#    #+#             */
/*   Updated: 2019/02/16 16:14:44 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		fill_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (0 <= x && x < fdf->p_win.sx && 0 <= y && y < fdf->p_win.sy)
		fdf->istr[x + y * fdf->p_win.sx] = color;
}

static int	grad(t_pos orig, t_pos current, t_pos end)
{
	float	r;
	int		color;
	t_pos	bot;
	t_pos	top;

	top = orig.x > end.x ? orig : end;
	bot = orig.x > end.x ? end : orig;
	r = fabsf((float)(current.x - bot.x) / (float)(top.x - bot.x));
	color = 0;
	color += 0x10000 * (int)((r * (top.c / 0x10000)) +
			((1 - r) * (bot.c / 0x10000)));
	color += 0x100 * (int)((r * (top.c % 0x10000 / 0x100)) +
			((1 - r) * (bot.c % 0x10000 / 0x100)));
	color += (int)((r * (top.c % 0x100)) + ((1 - r) * (bot.c % 0x100)));
	return (color);
}

void		fill_line(t_fdf *fdf, t_pos pos0, t_pos pos1)
{
	t_pos	d;
	t_pos	orig;
	int		err;
	int		e2;

	orig = pos0;
	d.x = ft_abs(pos1.x - pos0.x);
	d.y = ft_abs(pos1.y - pos0.y);
	d.z = (pos0.x < pos1.x ? 1 : -1);
	d.c = (pos0.y < pos1.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	fill_pixel(fdf, pos0.x, pos0.y, pos0.c);
	while (pos0.x != pos1.x || pos0.y != pos1.y)
	{
		fill_pixel(fdf, pos0.x, pos0.y, grad(orig, pos0, pos1));
		e2 = err;
		if (e2 > -d.x && ((err -= d.y) || 1))
			pos0.x += d.z;
		if (e2 < d.y && ((err += d.x) || 1))
			pos0.y += d.c;
	}
}

/*
** d.z = sx
** d.c = sy
*/

void		draw_line(t_fdf *fdf, t_pos pos0, t_pos pos1)
{
	t_pos	d;
	int		err;
	int		e2;

	d.x = ft_abs(pos1.x - pos0.x);
	d.y = ft_abs(pos1.y - pos0.y);
	d.z = (pos0.x < pos1.x ? 1 : -1);
	d.c = (pos0.y < pos1.y ? 1 : -1);
	err = (d.x > d.y ? d.x : -d.y) / 2;
	mlx_pixel_put(fdf->mlx, fdf->win, pos0.x, pos0.y, pos0.c);
	while (pos0.x != pos1.x || pos0.y != pos1.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, pos0.x, pos0.y, pos1.c);
		e2 = err;
		if (e2 > -d.x)
		{
			err -= d.y;
			pos0.x += d.z;
		}
		if (e2 < d.y)
		{
			err += d.x;
			pos0.y += d.c;
		}
	}
}
