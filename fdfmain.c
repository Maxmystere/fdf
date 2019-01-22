/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdfmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 16:53:32 by magrab            #+#    #+#             */
/*   Updated: 2019/01/22 16:08:11 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	fdf = init_mlx(ac, av);
	x = -1;
	while (++x < ac - 1)
	{
		mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
		mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
		mlx_mouse_hook(fdf[x].win, mouse_hook, &(fdf[x]));
	}
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
