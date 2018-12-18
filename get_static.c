/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   g_mlxptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 20:42:29 by magrab            #+#    #+#             */
/*   Updated: 2018/12/18 22:07:23 by magrab           ###   ########.fr       */
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

void	*g_win(int setup, int sizex, int sizey, char *win_name)
{
	static void *win_ptr;

	if (setup == 1)
		win_ptr = mlx_new_window(g_mlx(0), sizex, sizey, win_name);
	return (win_ptr);
}
