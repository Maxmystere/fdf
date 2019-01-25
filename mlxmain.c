/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/01/25 17:38:48 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_pos	**calcmap(int setup)
{
	static t_pos **test;

	if (setup == 1)
	{
		test = malloc(6 * sizeof(t_pos **));
		test[0] = malloc(4 * sizeof(t_pos));
		test[0][0].x = 0;
		test[0][0].y = 1;
		test[0][0].z = 0;
		test[0][0].c = 0xFF0000;
		test[0][1].x = 2;
		test[0][1].y = 3;
		test[0][1].z = 1;
		test[0][1].c = 0xFF8000;
		test[0][2].x = 2;
		test[0][2].y = 3;
		test[0][2].z = 0;
		test[0][2].c = 0xFF8000;
		test[0][3].c = -42;
		test[1] = malloc(4 * sizeof(t_pos));
		test[1][0].x = 4;
		test[1][0].y = 5;
		test[1][0].z = 2;
		test[1][0].c = 0xFF0080;
		test[1][1].x = 6;
		test[1][1].y = 7;
		test[1][1].z = 2;
		test[1][1].c = 0xFFFFFF;
		test[1][2].x = 6;
		test[1][2].y = 7;
		test[1][2].z = 3;
		test[1][2].c = 0xFFFFFF;
		test[1][3].c = -42;
		test[2] = malloc(4 * sizeof(t_pos));
		test[2][0].x = 8;
		test[2][0].y = 9;
		test[2][0].z = 4;
		test[2][0].c = 0xFFFFFF;
		test[2][1].x = 10;
		test[2][1].y = 11;
		test[2][1].z = 5;
		test[2][1].c = 0xFFFFFF;
		test[2][2].x = 10;
		test[2][2].y = 11;
		test[2][2].z = 5;
		test[2][2].c = 0xFFFFFF;
		test[2][3].c = -42;
		test[3] = malloc(4 * sizeof(t_pos));
		test[3][0].x = 12;
		test[3][0].y = 13;
		test[3][0].z = 6;
		test[3][0].c = 0xFFFFFF;
		test[3][1].x = 14;
		test[3][1].y = 15;
		test[3][1].z = 7;
		test[3][1].c = 0xFFFFFF;
		test[3][2].x = 14;
		test[3][2].y = 15;
		test[3][2].z = 7;
		test[3][2].c = 0xFFFFFF;
		test[3][3].c = -42;
		test[4] = malloc(4 * sizeof(t_pos));
		test[4][0].x = 12;
		test[4][0].y = 13;
		test[4][0].z = 6;
		test[4][0].c = 0xFFFFFF;
		test[4][1].x = 14;
		test[4][1].y = 15;
		test[4][1].z = 7;
		test[4][1].c = 0xFFFFFF;
		test[4][2].x = 14;
		test[4][2].y = 15;
		test[4][2].z = 7;
		test[4][2].c = 0xFFFFFF;
		test[4][3].c = -42;
		test[5] = NULL;
	}
	return (test);
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	if (!(fdf = init_mlx(ac, av, calcmap(1))))
		return (-1);
	x = -1;
	while (++x < ac - 1)
	{
		draw_iso(fdf, fdf->map, fdf->cam[0]);
		mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
		mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
		mlx_mouse_hook(fdf[x].win, mouse_hook, &(fdf[x]));
	}
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
