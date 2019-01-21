/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/01/21 19:39:36 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 53 : esc key
** 50 : key under esc
** 69 : plus numpad
** 78 : minus numpad
** 123 : left key
** 124 : right key
** 125 : down key
** 126 = up key
*/

int		key_press(int key, void *param)
{
	static int dx = 0;
	static int dy = 0;
	static int spc = 500;

	printf("key :%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 50)
		drawmap(calcmap(0), dx, dy, spc);
	if (key == 69)
		drawmap(calcmap(0), dx, dy, spc += 10);
	if (key == 78)
		drawmap(calcmap(0), dx, dy, spc -= 10);
	if (key == 123)
		drawmap(calcmap(0), dx -= 1, dy, spc);
	if (key == 124)
		drawmap(calcmap(0), dx += 1, dy, spc);
	if (key == 125)
		drawmap(calcmap(0), dx, dy += 1, spc);
	if (key == 126)
		drawmap(calcmap(0), dx, dy -= 1, spc);
	return (0);
}

int		key_release(int key, void *param)
{
	printf("key release :%d\n", key);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *win)
{
	printf("button :%d\n", button);
	return (0);
}

int		mouse_move(int x, int y, void *param)
{
	return (0);
}
