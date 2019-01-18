/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/01/18 16:27:50 by magrab           ###   ########.fr       */
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

int		key_hook(int key, void *param)
{
	static int dx = WINX / 2;
	static int dy = WINY / 2;
	static int spc = 0;

	printf("key :%d\n", key);
	if (key == 53)
		exit(0);
	if (key == 50)
		drawmap(calcmap(0), dx, dy, spc);
	if (key == 69)
		drawmap(calcmap(0), dx, dy, ++spc);
	if (key == 78)
		drawmap(calcmap(0), dx, dy, --spc);
	if (key == 123)
		drawmap(calcmap(0), --dx, dy, spc);
	if (key == 124)
		drawmap(calcmap(0), ++dx, dy, spc);
	if (key == 125)
		drawmap(calcmap(0), dx, ++dy, spc);
	if (key == 126)
		drawmap(calcmap(0), dx, --dy, spc);
	return (0);
}

int		mouse_hook(int button, int x, int y, void *win)
{
	printf("button :%d\n", button);
	test_draw(win, x, y);
	return (0);
}
