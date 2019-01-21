/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:30:03 by magrab            #+#    #+#             */
/*   Updated: 2019/01/21 19:40:08 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	fill_pixel(char *istr, int x, int y, int color)
{
	istr[x * 4 + y * 4 * 1000] = color % 0x100;
	istr[x * 4 + y * 4 * 1000 + 1] = color % 0x10000 / 0x100;
	istr[x * 4 + y * 4 * 1000 + 2] = color / 0x10000;
	istr[x * 4 + y * 4 * 1000 + 3] = color / 0x1000000;
}

void	draw_line(int x0, int y0, int x1, int y1)
{
	int		dx;
	int		dy;
	int		err;
	int		e2;

	dx = (int)fabs((double)(x1 - x0));
	dy = (int)fabs((double)(y1 - y0));
	err = (dx > dy ? dx : -dy);
	mlx_pixel_put(g_mlx(0), g_win(0), x0, y0, 0xFFFFFF);
	while (x0 != x1 || y0 != y1)
	{
		mlx_pixel_put(g_mlx(0), g_win(0), x0, y0, 0xFFFFFFFFFFF % 0x1000000);
		e2 = err;
		if (e2 > -dx)
		{
			err -= dy;
			x0 += (x0 < x1 ? 1 : -1);
		}
		if (e2 < dy)
		{
			err += dx;
			y0 += (y0 < y1 ? 1 : -1);
		}
	}
}

void	test_draw(void *win, int x, int y)
{
	static int x0;
	static int y0;
	static int x1;
	static int y1;

	if (x0 == 0)
	{
		x0 = x;
		y0 = y;
	}
	else if (x1 == 0)
	{
		x1 = x;
		y1 = y;
	}
	if (x0 != 0 && x1 != 0)
	{
		printf("draw :\nx0 = %d\ty0 = %d\nx1 = %d\ty1 = %d\n", x0, y0, x1, y1);
		draw_line(x0, y0, x1, y1);
		x0 = 0;
		x1 = 0;
		y0 = 0;
		y1 = 0;
	}
}
