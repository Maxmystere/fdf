/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:44:08 by magrab            #+#    #+#             */
/*   Updated: 2019/02/13 16:21:50 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** for iso
** x = posx from 0
** y = posy from 0
** z = addition to y for simili height
** rx = distance x*2 between each dot
** ry = distance y between each dot   // no need to modify it
** rz = distance x*2 and y between each dot
*/

static t_cam rotate_cam(t_fdf *fdf, t_cam pos)
{
	int tmp;

	tmp = pos.x;
	if (fdf->pr % 2)
		pos.rx = pos.rz * -2;
	else
		pos.rx = pos.rz * 2;
	pos.ry = pos.rz;
	return (pos);
}

static void iso_pos(t_fdf *fdf, t_cam pos, int x, int y)
{
	t_pos **tab;
	t_pos pos0;
	t_pos pos1;
	t_pos pos2;
	t_pos add;

	tab = fdf->map;
	add.z = (fdf->pr == 1 ? 1 : -1);
	add.x = pos.x - (tab[0][0].x / 2 - tab[0][0].y / 2) * pos.rx * add.z;
	add.y = pos.y - (tab[0][0].x / 2 + tab[0][0].y / 2) * pos.ry * add.z;
	pos0.x = (x - y) * pos.rx * add.z + add.x;
	pos0.y = (x + y) * pos.ry * add.z + tab[x][y].z * pos.z + add.y;
	pos0.c = tab[x][y].c;
	pos1.x = (x - (y + 1)) * pos.rx * add.z + add.x;
	pos1.y = (x + (y + 1)) * pos.ry * add.z + tab[x][y + 1].z * pos.z + add.y;
	pos1.c = tab[x][y + 1].c;
	pos2.x = (x - y + 1) * pos.rx * add.z + add.x;
	pos2.y = (x + 1 + y) * pos.ry * add.z + tab[x + 1][y].z * pos.z + add.y;
	pos2.c = tab[x + 1][y].c;
	fill_line(fdf, pos0, pos1);
	fill_line(fdf, pos0, pos2);
}

static void iso_pos2(t_fdf *fdf, t_cam pos, int x, int y)
{
	t_pos **tab;
	t_pos pos0;
	t_pos pos1;
	t_pos pos2;
	t_pos add;

	tab = fdf->map;
	add.x = pos.x - (tab[0][0].x / 2 + tab[0][0].y / 2) * pos.rx * (fdf->pr == 0 ? 1 : -1);
	add.y = pos.y - (tab[0][0].x / 2 - tab[0][0].y / 2) * pos.ry * (fdf->pr == 0 ? 1 : -1);
	pos0.x = (x + y) * pos.rx * (fdf->pr == 0 ? 1 : -1) + add.x;
	pos0.y = (x - y) * pos.ry * (fdf->pr == 0 ? 1 : -1) + tab[x][y].z * pos.z + add.y;
	pos0.c = tab[x][y].c;
	pos1.x = (x + (y + 1)) * pos.rx * (fdf->pr == 0 ? 1 : -1) + add.x;
	pos1.y = (x - (y + 1)) * pos.ry * (fdf->pr == 0 ? 1 : -1) + tab[x][y + 1].z * pos.z + add.y;
	pos1.c = tab[x][y + 1].c;
	pos2.x = (x + y + 1) * pos.rx * (fdf->pr == 0 ? 1 : -1) + add.x;
	pos2.y = (x + 1 - y) * pos.ry * (fdf->pr == 0 ? 1 : -1) + tab[x + 1][y].z * pos.z + add.y;
	pos2.c = tab[x + 1][y].c;
	fill_line(fdf, pos0, pos1);
	fill_line(fdf, pos0, pos2);
}

void *draw_iso(t_fdf *fdf, t_pos **tab, t_cam pos)
{
	int x;
	int y;

	fdf->istr = (int *)mlx_get_data_addr(fdf->img[ISO], &(fdf->bpp),
										 &(fdf->s_l), &(fdf->e));
	ft_bzero(fdf->istr, fdf->p_win.sx * fdf->p_win.sy * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	ft_printf("view : %d\n", fdf->pr);
	while (tab[x] && tab[x + 1])
	{
		y = 0;
		while (tab[x][y].c != -42 && tab[x][y + 1].c != -42)
		{
			if (fdf->pr % 2)
				iso_pos(fdf, rotate_cam(fdf, pos), x, y);
			else
				iso_pos2(fdf, rotate_cam(fdf, pos), x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img[ISO], 0, 0);
	fdf->istr = NULL;
	return (0);
}
