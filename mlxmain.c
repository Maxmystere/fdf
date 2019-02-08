/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/02/08 16:37:58 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	if (!(fdf = init_mlx(ac, av)))
		return (-1);
	x = -1;
	while (++x < ac - 1)
	{
		if (fdf[x].win)
		{
			draw_iso(&(fdf[x]), fdf[x].map, fdf[x].cam[0]);
			mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
			mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
			mlx_hook(fdf[x].win, 17, 0, close_hook, fdf);
			mlx_mouse_hook(fdf[x].win, mouse_hook, &(fdf[x]));
		}
	}
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
