/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mlxptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:42:29 by magrab            #+#    #+#             */
/*   Updated: 2019/01/17 19:38:43 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*g_mlx(int setup)
{
	static void *mlx_ptr;

	if (setup == 1)
		mlx_ptr = mlx_init();
	return (mlx_ptr);
}

void	*g_win(t_win *win)
{
	static void *win_ptr;

	if (win != 0)
		win_ptr = mlx_new_window(g_mlx(0), win->sizex, win->sizey, win->title);
	return (win_ptr);
}
