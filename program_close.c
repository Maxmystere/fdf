/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   program_close.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/25 20:23:43 by magrab            #+#    #+#             */
/*   Updated: 2019/01/25 20:23:44 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int close_hook(t_fdf *fdf)
{
    int     x;

    x = 0;
    while (x < MAXP)
    {
        mlx_destroy_image(fdf->mlx, fdf->img[x]);
        x++;
    }
    mlx_destroy_window(fdf->mlx, fdf->win);
    return (0);
}
