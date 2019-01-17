/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmlx.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 18:15:27 by magrab            #+#    #+#             */
/*   Updated: 2019/01/17 19:47:53 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_value	**calcmap(int setup)
{
	static t_value **test;

	if (setup == 1)
	{
		test = malloc(4 * sizeof(t_value **));
		test[0] = malloc(3 * sizeof(t_value));
		test[0][0].x = 0;
		test[0][0].y = 0;
		test[0][0].z = 5;
		test[0][0].c = 0xFFFFFF;
		test[0][1].x = 0;
		test[0][1].y = 1;
		test[0][1].z = 4;
		test[0][1].c = 0xFFFFFF;
		test[0][2].c = -42;
		test[1] = malloc(3 * sizeof(t_value));
		test[1][0].x = 1;
		test[1][0].y = 0;
		test[1][0].z = 3;
		test[1][0].c = 0xFFFFFF;
		test[1][1].x = 1;
		test[1][1].y = 1;
		test[1][1].z = 2;
		test[1][1].c = 0xFFFFFF;
		test[1][2].c = -42;
		test[2] = malloc(3 * sizeof(t_value));
		test[2][0].x = 2;
		test[2][0].y = 0;
		test[2][0].z = 1;
		test[2][0].c = 0xFFFFFF;
		test[2][1].x = 2;
		test[2][1].y = 1;
		test[2][1].z = 0;
		test[2][1].c = 0xFFFFFF;
		test[2][2].c = -42;
		test[3] = NULL;
	}
	return (test);
}

int		drawmap(t_value **test, int dx, int dy, int space)
{
	int x;
	int y;

	x = 0;
	y = 0;
	mlx_clear_window(g_mlx(0), g_win(0));
	if (!test)
		return (-1);
	while (test[x])
	{
		while (test[x][y].c != -42)
		{
			mlx_pixel_put(g_mlx, g_win(0),
					dx + test[x][y].x + test[x][y].x * space,
					dy + test[x][y].y + test[x][y].y * space,
					test[x][y].c);
			y++;
		}
		y = 0;
		x++;
	}
	return (0);
}

int		main(void)
{
	t_win window;

	window.sizex = 1000;
	window.sizey = 1000;
	window.title = "TEST";
	if (!g_mlx(1))
		return (-1);
	if (!(g_win(&window)))
		return (-1);
	
	mlx_key_hook(g_win(0), key_hook, g_win(0));
	mlx_mouse_hook(g_win(0), mouse_hook, g_win(0));

	calcmap(1);

	drawmap(calcmap(0), 0, 0, 0);

	mlx_loop(g_mlx(0));
	return (0);
}
