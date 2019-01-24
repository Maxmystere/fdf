/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/01/24 16:50:17 by magrab           ###   ########.fr       */
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
		test[0][0].y = 0;
		test[0][0].z = 0;
		test[0][0].c = 0xFF0000;
		test[0][1].x = 0;
		test[0][1].y = 0;
		test[0][1].z = 10;
		test[0][1].c = 0xFF8000;
		test[0][2].c = -42;
		test[1] = malloc(3 * sizeof(t_pos));
		test[1][0].x = 0;
		test[1][0].y = 10;
		test[1][0].z = 0;
		test[1][0].c = 0xFF0080;
		test[1][1].x = 0;
		test[1][1].y = 10;
		test[1][1].z = 10;
		test[1][1].c = 0xFFFFFF;
		test[1][2].c = -42;
		test[2] = malloc(3 * sizeof(t_pos));
		test[2][0].x = 10;
		test[2][0].y = 0;
		test[2][0].z = 0;
		test[2][0].c = 0xFFFFFF;
		test[2][1].x = 10;
		test[2][1].y = 0;
		test[2][1].z = 10;
		test[2][1].c = 0xFFFFFF;
		test[2][2].c = -42;
		test[3] = malloc(3 * sizeof(t_pos));
		test[3][0].x = 10;
		test[3][0].y = 10;
		test[3][0].z = 0;
		test[3][0].c = 0xFFFFFF;
		test[3][1].x = 10;
		test[3][1].y = 10;
		test[3][1].z = 10;
		test[3][1].c = 0xFFFFFF;
		test[3][2].c = -42;
		test[4] = NULL;
	}
	return (test);
}

void draw_map(t_fdf *fdf, t_pos pos)
{
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
