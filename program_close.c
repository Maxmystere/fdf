/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:23:43 by magrab            #+#    #+#             */
/*   Updated: 2019/01/25 23:52:50 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_hook(t_fdf *fdf)
{
    int     x;

    x = 0;
    while (x < MAXP)
    {
        //mlx_destroy_image(fdf->mlx, fdf->img[x]);
        x++;
    }
    x = 0;
    while (fdf[x].mlx)
    {
        printf("fdf %p\t%s\n", fdf[x].mlx, fdf[x].p_win.title);
        x++;
    }
    //mlx_destroy_window(fdf->mlx, fdf->win);
    //printf("win %p\n", fdf->win);
	//exit(0);
    return (0);
}
