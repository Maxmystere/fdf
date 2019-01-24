/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/01/24 16:34:50 by magrab           ###   ########.fr       */
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

t_cam	move_pos(t_fdf *fdf, int key)
{
	if (key == 123)
		fdf->cam.x--;
	else if (key == 124)
		fdf->cam.x++;
	else if (key == 125)
		fdf->cam.y++;
	else if (key == 126)
		fdf->cam.y--;
	//ft_printf("cam pos :\nx = %d\ny = %d\n", fdf->cam.x, fdf->cam.y);
	return (fdf->cam);
}

int		key_press(int key, t_fdf *fdf)
{
	if (key == 53)
		exit(0);
	if (123 <= key && key <= 126)
		draw_map(fdf, fdf->map, move_pos(fdf, key));
	else
		ft_printf("win : %s\tkey :%d\n", fdf->p_win.title, key);
	/*
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
	*/
	return (0);
}

int		key_release(int key, t_fdf *fdf)
{
	printf("key release :%d\n", key);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	printf("button :%d\n", button);
	test_draw(fdf, x, y);
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	return (0);
}
