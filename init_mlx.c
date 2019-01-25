/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:34:47 by magrab            #+#    #+#             */
/*   Updated: 2019/01/21 19:39:58 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
/*
static t_cam *basic_cam(void)
{
	t_cam	cam[MAXP];
	int		x;

	while (x < MAXP)
	{
		cam[x].x = 0;
		cam[x].y = 0;
		cam[x].z = 0;
		cam[x].rx = 0;
		cam[x].ry = 0;
		cam[x].rz = 0;
		x++;
	}
	return (cam);
}
*/
t_fdf *init_mlx(int winnb, char **winname, t_pos **map)
{
	size_t	v;
	t_fdf	*fdf;
	void	*mlx;

	if (winnb < 2)
		return (NULL);
	if (!(fdf = malloc(sizeof(t_fdf) * winnb)))
		return (NULL);
	if (!(mlx = mlx_init()))
		return (NULL);
	v = -1;
	while (++v < winnb - 1)
	{
		fdf[v].mlx = mlx;
//		fdf[v].cam = basic_cam();
		fdf[v].p_win.sx = WINX;
		fdf[v].p_win.sy = WINY;
		fdf[v].map = map;
		fdf[v].p_win.title = winname[v + 1];
		if (!(fdf[v].win = mlx_new_window(mlx, WINX, WINY, winname[v + 1])))
			return (NULL);
		fdf[v].img[0] = NULL;
	}
	return (fdf);
}
