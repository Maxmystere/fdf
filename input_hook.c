/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deal_input.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:01:03 by magrab            #+#    #+#             */
/*   Updated: 2018/12/18 22:03:16 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	key_hook(int key, void *param)
{
	printf("key :%d\n", key);

	if (key == 53) //esc key
		exit(0);
	if (key == 50)
		mlx_clear_window(g_mlx(0), param);
	return (0);
}

int mouse_hook(int button, int x, int y, void *win)
{
	printf("button :%d\n", button);

	test_draw(win,x, y);
	return (0);
}
