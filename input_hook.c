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
** 18 : 1 key
** 19 : 2 key
** 20 : 3 key
** 21 : 4 key
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

int		key_press(int key, t_fdf *fdf)
{
	if (key == 53)
		close_hook(fdf);
	if ((18 <= key && key <= 21) || key == 69 || key == 78 || (83 <= key && key <= 92) || (123 <= key && key <= 126))
		draw_iso(change_projection(fdf, key), fdf->map, move_pos(fdf, key));
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
