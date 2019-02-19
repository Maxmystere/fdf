/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/02/19 15:33:01 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 18 : 1 key
** 19 : 2 key
** 20 : 3 key
** 21 : 4 key
** 46 : M key
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

int	key_press(int key, t_fdf *fdf)
{
	if (key == 53)
		return (close_hook(fdf));
	if (18 <= key && key <= 20)
		fdf->mouse.x = 0;
	if (key != 46 || !ft_nodesearch_int(fdf->keys, 46))
		ft_nodeadd_int(&(fdf->keys), key);
	else
		ft_noderm_int(&(fdf->keys), 46);
	return (0);
}

int	key_release(int key, t_fdf *fdf)
{
	if (key != 46)
		ft_noderm_int(&(fdf->keys), key);
	ft_printf("%s\tkey release :%d\n", fdf->p_win.title, key);
	return (0);
}

int	mouse_press(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1)
	{
		if (x > 0 && y > 0)
		{
			fdf->mouse.x = fdf->cam[fdf->cp].x - x;
			fdf->mouse.y = fdf->cam[fdf->cp].y - y;
		}
	}
	else if (button == 4 || button == 5)
	{
		move_iso(fdf, (button == 4 ? -4 : -5));
		move_carre(fdf, (button == 4 ? -4 : -5));
		move_flat(fdf, (button == 4 ? -4 : -5));
		if (fdf->cp == ISO)
			draw_tilt(fdf, fdf->map, fdf->cam[fdf->cp]);
		else if (fdf->cp == CARRE)
			draw_tilt(fdf, fdf->map, fdf->cam[fdf->cp]);
		else if (fdf->cp == FLAT)
			draw_flat(fdf, fdf->map, fdf->cam[fdf->cp]);
		if (ft_nodesearch_int(fdf->keys, 46))
			show_menu(fdf);
	}
	ft_printf("button :%d\tpos: %d\t%d\n", button, x, y);
	return (0);
}

int	mouse_release(int button, int x, int y, t_fdf *fdf)
{
	if (button == 1)
	{
		fdf->mouse.x = 0;
		fdf->mouse.y = 0;
	}
	ft_printf("button :%d\tpos: %d\t%d\n", button, x, y);
	return (0);
}

int	mouse_move(int x, int y, t_fdf *fdf)
{
	if (fdf->mouse.x)
	{
		fdf->cam[fdf->cp].x = fdf->mouse.x + x;
		fdf->cam[fdf->cp].y = fdf->mouse.y + y;
	}
	return (0);
}
