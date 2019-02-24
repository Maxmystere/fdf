/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_flat.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 19:39:12 by magrab            #+#    #+#             */
/*   Updated: 2019/02/24 16:06:15 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

static void	init_add(t_pos *add, t_cam pos, t_fdf *fdf)
{
	add->x = pos.x - (fdf->p_m.y / 2 * pos.rx + fdf->p_m.x / 2 * pos.ry);
	add->y = pos.y - (fdf->p_m.y / 2 * pos.rx);
	add->z = 1;
	add->c = 1;
}

void		drawer(t_fdf *fdf, t_cam pos, int x, int y)
{
	t_map	**tab;
	t_pos	pos0;
	t_pos	pos1;
	t_pos	pos2;
	t_pos	add;

	tab = fdf->map;
	init_add(&add, pos, fdf);
	pos0.x = x * pos.rx + y * pos.ry + add.x;
	pos0.y = x * pos.rx + tab[x][y].z * pos.z + add.y;
	pos0.c = tab[x][y].c;
	if (tab[x][y + 1].c != -42)
	{
		pos1.x = x * pos.rx + (y + 1) * pos.ry + add.x;
		pos1.y = x * pos.rx + tab[x][y + 1].z * pos.z + add.y;
		pos1.c = tab[x][y + 1].c;
		fill_line(fdf, pos0, pos1);
	}
	if (tab[x + 1])
	{
		pos2.x = (x + 1) * pos.rx + y * pos.ry + add.x;
		pos2.y = (x + 1) * pos.rx + tab[x + 1][y].z * pos.z + add.y;
		pos2.c = tab[x + 1][y].c;
		fill_line(fdf, pos0, pos2);
	}
}

void		*draw_flat(t_fdf *fdf, t_map **tab, t_cam pos)
{
	int x;
	int y;

	fdf->istr = (int *)mlx_get_data_addr(fdf->img[fdf->cp], &(fdf->bpp),
														&(fdf->s_l), &(fdf->e));
	ft_bzero(fdf->istr, fdf->p_win.sx * fdf->p_win.sy * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	while (tab[x])
	{
		y = 0;
		while (tab[x][y].c != -42)
		{
			drawer(fdf, pos, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img[fdf->cp], 0, 0);
	draw_text(fdf, fdf->p_win.sx - 60, 30);
	fdf->istr = NULL;
	return (0);
}
