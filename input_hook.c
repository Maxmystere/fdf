/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/02/08 18:11:09 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 53 : esc key
** 50 : key under esc
** 69 : plus numpad
** 78 : minus numpad
** 84 : num 2
** 91 : num 8
** 123 : left key
** 124 : right key
** 125 : down key
** 126 = up key
*/

t_cam	move_pos(t_fdf *fdf, int key)
{
	if (key == 69)
		fdf->cam[fdf->cp].z--;
	else if (key == 78)
		fdf->cam[fdf->cp].z++;
	else if (key == 84)
		fdf->cam[fdf->cp].rz--;
	else if (key == 91)
		fdf->cam[fdf->cp].rz++;
	else if (key == 123)
		fdf->cam[fdf->cp].x--;
	else if (key == 124)
		fdf->cam[fdf->cp].x++;
	else if (key == 125)
		fdf->cam[fdf->cp].y++;
	else if (key == 126)
		fdf->cam[fdf->cp].y--;
	return (fdf->cam[fdf->cp]);
}

int		key_press(int key, t_fdf *fdf)
{
	if (key == 53)
		close_hook(fdf);
	if (key == 69 || key == 78 || (83 <= key && key <= 92) || (123 <= key && key <= 126))
		draw_iso(fdf, fdf->map, move_pos(fdf, key));
	else
		ft_printf("win : %s\tkey :%d\n", fdf->p_win.title, key);
	return (0);
}

int		key_release(int key, t_fdf *fdf)
{
	ft_printf("key release :%d\n", key);
	return (0);
}

int		mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	ft_printf("button :%d\tpos: %d\t%d\n", button, x, y);
	//test_draw(fdf, x, y);
	return (0);
}

int		mouse_move(int x, int y, t_fdf *fdf)
{
	return (0);
}
