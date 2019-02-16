/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:32:14 by tferrieu          #+#    #+#             */
/*   Updated: 2019/02/16 16:32:17 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_boussole(t_fdf *fdf, int x, int y)
{
	if (fdf->pr % 2 == 0)
	{
		mlx_string_put(fdf->mlx, fdf->win, x - 5, y - 10, (fdf->pr == 0 ?
												0xF44141 : 0xFFFFFF), "/\\");
		mlx_string_put(fdf->mlx, fdf->win, x - 5, y + 10, (fdf->pr == 0 ?
												0xFFFFFF : 0xF44141), "\\/");
	}
	else if (fdf->pr % 2)
	{
		mlx_string_put(fdf->mlx, fdf->win, x + 10, y + 2, (fdf->pr == 1 ?
												0xF44141 : 0xFFFFFF), ">");
		mlx_string_put(fdf->mlx, fdf->win, x - 10, y + 2, (fdf->pr == 1 ?
												0xFFFFFF : 0xF44141), "<");
	}
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, "o");
}

void			draw_text(t_fdf *fdf, int x, int y)
{
	draw_boussole(fdf, x, y);
	mlx_string_put(fdf->mlx, fdf->win, x / 2, y, 0xFFFFFF, fdf->winstr);

}

void			show_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF,
								"/  Tuto !                              \\");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFFF,
								"|  Change Projection : 1, 2, 3         |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFFF,
								"|  Press current Projection to rotate  |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFFF,
								"|  Move : Arrow Keys                   |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF,
								"|  Change Altitude : + / -             |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFFF,
								"|  Zoom in/out : 8 / 2 (NUMPAD         |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 130, 0xFFFFFF,
								"|  Show this Menu : M                  |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 170, 0xFFFFFF,
								"|  Quit : Esc                          |");
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	if (!(fdf = init_mlx(ac, av)))
		return (-1);
	x = -1;
	mlx_do_key_autorepeatoff(fdf->mlx);
	while (++x < ac - 1)
	{
		if (fdf[x].win)
		{
			draw_tilt(&(fdf[x]), fdf[x].map, fdf[x].cam[0]);
			show_menu(&(fdf[x]));
			mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
			mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
			mlx_hook(fdf[x].win, 17, 0, close_hook, &(fdf[x]));
			mlx_mouse_hook(fdf[x].win, mouse_hook, &(fdf[x]));
		}
	}
	mlx_loop_hook(fdf->mlx, loop_hook, fdf);
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
