/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/01/24 17:57:33 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	**calcmap(int setup)
{
	static t_pos **test;

	if (setup == 1)
	{
		test = malloc(5 * sizeof(t_pos **));
		test[0] = malloc(3 * sizeof(t_pos));
		test[0][0].x = 0;
		test[0][0].y = 1;
		test[0][0].z = 0;
		test[0][0].c = 0xFF0000;
		test[0][1].x = 2;
		test[0][1].y = 3;
		test[0][1].z = 10;
		test[0][1].c = 0xFF8000;
		test[0][2].c = -42;
		test[1] = malloc(3 * sizeof(t_pos));
		test[1][0].x = 4;
		test[1][0].y = 5;
		test[1][0].z = 0;
		test[1][0].c = 0xFF0080;
		test[1][1].x = 6;
		test[1][1].y = 7;
		test[1][1].z = 0;
		test[1][1].c = 0xFFFFFF;
		test[1][2].c = -42;
		test[2] = malloc(3 * sizeof(t_pos));
		test[2][0].x = 8;
		test[2][0].y = 9;
		test[2][0].z = 0;
		test[2][0].c = 0xFFFFFF;
		test[2][1].x = 10;
		test[2][1].y = 11;
		test[2][1].z = 10;
		test[2][1].c = 0xFFFFFF;
		test[2][2].c = -42;
		test[3] = malloc(3 * sizeof(t_pos));
		test[3][0].x = 12;
		test[3][0].y = 13;
		test[3][0].z = 0;
		test[3][0].c = 0xFFFFFF;
		test[3][1].x = 14;
		test[3][1].y = 15;
		test[3][1].z = 10;
		test[3][1].c = 0xFFFFFF;
		test[3][2].c = -42;
		test[4] = NULL;
	}
	return (test);
}

void *draw_map(t_fdf *fdf, t_pos **tab, t_cam pos)
{
	int		x;
	int		y;
	t_pos	pos0;
	t_pos	pos1;
	t_pos	pos2;

	if (!(fdf->img = mlx_new_image(fdf->mlx, fdf->p_win.sizex, fdf->p_win.sizey)))
		return (0);
	if (!(fdf->istr = (int *)mlx_get_data_addr(fdf->img, &(fdf->bpp), &(fdf->size_line), &(fdf->endian))))
		return (0);
	mlx_clear_window(fdf->mlx, fdf->win);
	x = 0;
	while (tab[x] && tab[x + 1])
	{
		y = 0;
		while (tab[x][y].c != -42 && tab[x][y + 1].c != -42)
		{
			pos0.x = (x - y) * 64;
			pos0.y = (x + y) * 32;
			pos0.c = tab[x][y].c;
			pos1.x = (x - (y + 1)) * 64;
			pos1.y = (x + (y + 1)) * 32;
			pos1.c = tab[x][y + 1].c;
			pos2.x = (x + 1 - y) * 64;
			pos2.y = (x + 1 + y) * 32;
			pos2.c = tab[x + 1][y].c;
			//fill_pixel(fdf->istr, pos.x + (x - y) * 64, pos.y + (x + y) * 32, 0xFFFFFF);
			fill_line(fdf, pos0, pos1);
			fill_line(fdf, pos0, pos2);
			ft_printf("pos %d\t%d\n", tab[x][y].x, tab[x][y].y);
			y++;
		}
		x++;
	}
	//mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
	mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, pos.x, pos.y);
	mlx_destroy_image(fdf->mlx, fdf->img);
	return (0);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	if (!(fdf = init_mlx(ac, av)))
		return (-1);
	x = -1;
	while (++x < ac - 1)
	{
		mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
		mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
		mlx_mouse_hook(fdf[x].win, mouse_hook, &(fdf[x]));
		// Try read map
	}
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
