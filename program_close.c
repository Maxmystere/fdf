/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:23:43 by magrab            #+#    #+#             */
/*   Updated: 2019/02/16 18:25:28 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** nwin = number of left windows
** while fdf[x].mlx will check if there is any other windows opened and will
** close if there isnt any left
*/

int		close_hook(t_fdf *fdf)
{
	int		x;
	int		nwin;

	x = 0;
	while (x < MAXP)
	{
		mlx_destroy_image(fdf->mlx, fdf->img[x]);
		x++;
	}
	mlx_destroy_window(fdf->mlx, fdf->win);
	clean_postab(fdf->map);
	fdf->map = NULL;
	fdf->win = NULL;
	nwin = 0;
	x = -fdf->p_win.nb;
	while (fdf[x].mlx)
	{
		if (fdf[x].win)
			nwin++;
		x++;
	}
	if (nwin == 0)
		exit(0);
	return (0);
}
