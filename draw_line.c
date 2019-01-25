/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:30:03 by magrab            #+#    #+#             */
/*   Updated: 2019/01/24 17:02:05 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(t_fdf *fdf, int x, int y, int color)
{
	if (0 <= x && x < fdf->p_win.sx && 0 <= y && y < fdf->p_win.sy)
		fdf->istr[x + y * fdf->p_win.sx] = color;
}

void	fill_line(t_fdf *fdf, t_pos pos0, t_pos pos1)
{
	int		dx;
	int		dy;
	int		err;
	int		e2;

	dx = (int)fabs((double)(pos1.x - pos0.x));
	dy = (int)fabs((double)(pos1.y - pos0.y));
	err = (dx > dy ? dx : -dy);
	fill_pixel(fdf, pos0.x, pos0.y, pos0.c);
	while (pos0.x != pos1.x || pos0.y != pos1.y)
	{
		fill_pixel(fdf, pos0.x, pos0.y, pos0.c);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pos0.x += (pos0.x < pos1.x ? 1 : -1);
		}
		if (e2 < dy)
		{
			err += dx;
			pos0.y += (pos0.y < pos1.y ? 1 : -1);
		}
	}
}

void	draw_line(t_fdf *fdf, t_pos pos0, t_pos pos1)
{
	int		dx;
	int		dy;
	int		err;
	int		e2;

	dx = (int)fabs((double)(pos1.x - pos0.x));
	dy = (int)fabs((double)(pos1.y - pos0.y));
	err = (dx > dy ? dx : -dy);
	mlx_pixel_put(fdf->mlx, fdf->win, pos0.x, pos0.y, pos0.c);
	while (pos0.x != pos1.x || pos0.y != pos1.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, pos0.x, pos0.y, pos1.c);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			pos0.x += (pos0.x < pos1.x ? 1 : -1);
		}
		if (e2 < dy)
		{
			err += dx;
			pos0.y += (pos0.y < pos1.y ? 1 : -1);
		}
	}
}

void	test_draw(t_fdf *fdf, int x, int y)
{
	static t_pos pos0 = {0, 0};
	static t_pos pos1 = {0, 0};

	if (pos0.x == 0)
	{
		pos0.x = x;
		pos0.y = y;
		pos0.c = 0xFFFFFF;
	}
	else if (pos1.x == 0)
	{
		pos1.x = x;
		pos1.y = y;
		pos1.c = 0xFFFFFF;
	}
	if (pos0.x != 0 && pos1.x != 0)
	{
		draw_line(fdf, pos0, pos1);
		pos0.x = 0;
		pos0.y = 0;
		pos1.x = 0;
		pos1.y = 0;
	}
}
