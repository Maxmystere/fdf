/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:44:08 by magrab            #+#    #+#             */
/*   Updated: 2019/02/08 18:48:54 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** for iso
** x = posx from 0
** y = posy from 0
** z = addition to y for simili height
** rz = distance x*2 and y between each dot
*/

void	*draw_iso(t_fdf *fdf, t_pos **tab, t_cam pos)
{
	int		x;
	int		y;
	t_pos	pos0;
	t_pos	pos1;
	t_pos	pos2;

	fdf->istr = (int *)mlx_get_data_addr(fdf->img[ISO], &(fdf->bpp),
			&(fdf->s_l), &(fdf->e));
	ft_bzero(fdf->istr, fdf->p_win.sx * fdf->p_win.sy * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	while (tab[x] && tab[x + 1])
	{
		y = 0;
		while (tab[x][y].c != -42 && tab[x][y + 1].c != -42)
		{
			pos0.x = (x - y) * pos.rz * -2 + pos.x;
			pos0.y = (x + y) * pos.rz + tab[x][y].z * pos.z + pos.y;
			pos0.c = tab[x][y].c;
			pos1.x = (x - (y + 1)) * pos.rz * -2 + pos.x;
			pos1.y = (x + (y + 1)) * pos.rz + tab[x][y + 1].z * pos.z + pos.y;
			pos1.c = tab[x][y + 1].c;
			pos2.x = (x + 1 - y) * pos.rz * -2 + pos.x;
			pos2.y = (x + 1 + y) * pos.rz + tab[x + 1][y].z * pos.z + pos.y;
			pos2.c = tab[x + 1][y].c;
			fill_line(fdf, pos0, pos1);
			fill_line(fdf, pos0, pos2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img[ISO], 0, 0);
	fdf->istr = NULL;
	return (0);
}
