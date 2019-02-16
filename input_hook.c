/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_hook.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2019/02/16 13:01:48 by magrab           ###   ########.fr       */
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

int key_press(int key, t_fdf *fdf)
{
	t_tab pos;
	int mkey;

	if (key == 53)
		return (close_hook(fdf));
	ft_nodeadd_int(&(fdf->keys), key);
	return (0);
}

int key_release(int key, t_fdf *fdf)
{
	ft_noderm_int(&(fdf->keys), key);
	ft_printf("key release :%d\n", key);
	return (0);
}

int mouse_hook(int button, int x, int y, t_fdf *fdf)
{
	ft_printf("button :%d\tpos: %d\t%d\n", button, x, y);
	//test_draw(fdf, x, y);
	return (0);
}

int mouse_move(int x, int y, t_fdf *fdf)
{
	return (0);
}

int loop_hook(t_fdf *fdf)
{
	int x;
	t_tab pos;
	int mkey;

	x = 0;
	while (fdf[x].mlx)
	{
		if (fdf[x].win)
		{
			ft_nodeprint_int(fdf[x].keys);
			if (fdf[x].keys)
			{
				pos = fdf->keys;
				while (pos)
				{
					mkey = pos->data;
					change_projection(fdf, mkey);
					if (mkey == 46)
						show_menu(fdf);
					else if (fdf->cp == ISO)
						move_iso(fdf, mkey);
					else if (fdf->cp == CARRE)
						move_carre(fdf, mkey);
					else if (fdf->cp == FLAT)
						move_carre(fdf, mkey);
					else if (mkey == 18)
						ft_noderm_int(&(fdf->keys), 18);
					pos = pos->next;
				}
				if (fdf->cp == ISO)
					draw_tilt(fdf, fdf->map, fdf->cam[fdf->cp]);
				else if (fdf->cp == CARRE)
					draw_tilt(fdf, fdf->map, fdf->cam[fdf->cp]);
				else if (fdf->cp == FLAT)
					draw_flat(fdf, fdf->map, fdf->cam[fdf->cp]);
			}
		}
		x++;
	}
	return (0);
}
