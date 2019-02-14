/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/02/14 14:15:46 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void			show_menu(t_fdf *fdf)
{
	mlx_string_put(fdf->mlx, fdf->win, 10, 10, 0xFFFFFF, "/  Tuto !                              \\");
	mlx_string_put(fdf->mlx, fdf->win, 10, 30, 0xFFFFFF, "|  Change Projection : 1, 2, 3         |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 50, 0xFFFFFF, "|  Press current Projection to rotate  |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 70, 0xFFFFFF, "|  Move : Arrow Keys                   |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 90, 0xFFFFFF, "|  Change Altitude : + / -             |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 110, 0xFFFFFF,"|  Zoom in/out : 8 / 2 (NUMPAD         |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 130, 0xFFFFFF,"|  Show this Menu : M                  |");
	mlx_string_put(fdf->mlx, fdf->win, 10, 170, 0xFFFFFF,"|  Quit : Esc                          |");
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
