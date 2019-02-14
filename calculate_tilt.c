/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:44:08 by magrab            #+#    #+#             */
/*   Updated: 2019/02/13 19:20:11 by magrab           ###   ########.fr       */
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
** rz = distance x*2 and y between each dot // Deprecated
*/

static t_pos	reduceline(t_fdf *fdf, t_cam pos, int function)
{
	t_pos	add;

	if (function == 0)
	{
		add.z = (fdf->pr == 1 ? 1 : -1);
		add.c = (fdf->pr % 2 ? -1 : 1);
		add.x = pos.x - (fdf->p_m.x / 2 - fdf->p_m.y / 2)
			* pos.rx * add.z * add.c;
		add.y = pos.y - (fdf->p_m.x / 2 + fdf->p_m.y / 2) * pos.ry * add.z;
	}
	else
	{
		add.z = (fdf->pr == 0 ? 1 : -1);
		add.c = (fdf->pr % 2 ? -1 : 1);
		add.x = pos.x - (fdf->p_m.x / 2 + fdf->p_m.y / 2) * pos.rx * add.z;
		add.y = pos.y - (fdf->p_m.x / 2 - fdf->p_m.y / 2) * pos.ry * add.z;
	}
	return (add);
}

static void		iso_pos(t_fdf *fdf, t_cam pos, int x, int y)
{
	t_map **tab;
	t_pos pos0;
	t_pos pos1;
	t_pos pos2;
	t_pos add;

	tab = fdf->map;
	add = reduceline(fdf, pos, 0);
	pos0.x = (x - y) * pos.rx * add.z * add.c + add.x;
	pos0.y = (x + y) * pos.ry * add.z + tab[x][y].z * pos.z + add.y;
	pos0.c = tab[x][y].c;
	if (tab[x][y + 1].c != -42)
	{
		pos1.x = (x - (y + 1)) * pos.rx * add.z * add.c + add.x;
		pos1.y = (x + y + 1) * pos.ry * add.z + tab[x][y + 1].z * pos.z + add.y;
		pos1.c = tab[x][y + 1].c;
		fill_line(fdf, pos0, pos1);
	}
	if (tab[x + 1])
	{
		pos2.x = (x - y + 1) * pos.rx * add.z * add.c + add.x;
		pos2.y = (x + 1 + y) * pos.ry * add.z + tab[x + 1][y].z * pos.z + add.y;
		pos2.c = tab[x + 1][y].c;
		fill_line(fdf, pos0, pos2);
	}
}

static void		iso_pos2(t_fdf *fdf, t_cam pos, int x, int y)
{
	t_map **tab;
	t_pos pos0;
	t_pos pos1;
	t_pos pos2;
	t_pos add;

	tab = fdf->map;
	add = reduceline(fdf, pos, 1);
	pos0.x = (x + y) * pos.rx * add.z + add.x;
	pos0.y = (x - y) * pos.ry * add.z + tab[x][y].z * pos.z + add.y;
	pos0.c = tab[x][y].c;
	if (tab[x][y + 1].c != -42)
	{
		pos1.x = (x + (y + 1)) * pos.rx * add.z + add.x;
		pos1.y = (x - y - 1) * pos.ry * add.z + tab[x][y + 1].z * pos.z + add.y;
		pos1.c = tab[x][y + 1].c;
		fill_line(fdf, pos0, pos1);
	}
	if (tab[x + 1])
	{
		pos2.x = (x + y + 1) * pos.rx * add.z + add.x;
		pos2.y = (x + 1 - y) * pos.ry * add.z + tab[x + 1][y].z * pos.z + add.y;
		pos2.c = tab[x + 1][y].c;
		fill_line(fdf, pos0, pos2);
	}
}

void			*draw_tilt(t_fdf *fdf, t_map **tab, t_cam pos)
{
	int x;
	int y;

	fdf->istr = (int *)mlx_get_data_addr(fdf->img[fdf->cp], &(fdf->bpp),
			&(fdf->s_l), &(fdf->e));
	ft_bzero(fdf->istr, fdf->p_win.sx * fdf->p_win.sy * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = (fdf->pr == 2 ? 0 : fdf->p_m.x - 1);
	while (x >= 0 && tab[x])
	{
		y = 0;
		while (tab[x][y].c != -42)
		{
			if (fdf->pr % 2)
				iso_pos(fdf, pos, x, y);
			else
				iso_pos2(fdf, pos, x, y);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img[fdf->cp], 0, 0);
	fdf->istr = NULL;
	return (0);
}
