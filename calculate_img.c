/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_img.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 19:44:08 by magrab            #+#    #+#             */
/*   Updated: 2019/01/25 19:44:09 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void *draw_iso(t_fdf *fdf, t_pos **tab, t_cam pos)
{
	int		x;
	int		y;
	t_pos	pos0;
	t_pos	pos1;
	t_pos	pos2;

	fdf->istr = (int *)mlx_get_data_addr(fdf->img[ISO], &(fdf->bpp),
		&(fdf->s_l), &(fdf->e));
    bzero(fdf->istr, WINX * WINY * 4);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	while (tab[x] && tab[x + 1])
	{
		y = 0;
		while (tab[x][y].c != -42 && tab[x][y + 1].c != -42)
		{
			pos0.x = (x - y) * 64 + fdf->p_win.sx / 2;
			pos0.y = (x + y) * 32 + fdf->p_win.sy / 2 + tab[x][y].z * pos.z;
			pos0.c = tab[x][y].c;
			pos1.x = (x - (y + 1)) * 64 + fdf->p_win.sx / 2;
			pos1.y = (x + (y + 1)) * 32 + fdf->p_win.sy / 2 + tab[x][y + 1].z * pos.z;
			pos1.c = tab[x][y + 1].c;
			pos2.x = (x + 1 - y) * 64 + fdf->p_win.sx / 2;
			pos2.y = (x + 1 + y) * 32 + fdf->p_win.sy / 2 + tab[x + 1][y].z * pos.z;
			pos2.c = tab[x + 1][y].c;
            printf("pos0\t%d\t%d\t%x\npos1\t%d\t%d\t%x\npos2\t%d\t%d\t%x\n", pos0.x, pos0.y, pos0.c, pos1.x, pos1.y, pos1.c, pos2.x, pos2.y, pos2.c);
			fill_line(fdf, pos0, pos1);
			fill_line(fdf, pos0, pos2);
			y++;
		}
		x++;
	}
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img[ISO], pos.x, pos.y);
	//mlx_destroy_image(fdf->mlx, fdf->img[0]);
	fdf->istr = NULL;
	return (0);
}
