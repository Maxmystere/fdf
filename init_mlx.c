/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:34:47 by magrab            #+#    #+#             */
/*   Updated: 2019/02/08 18:19:35 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void	basic_cam(t_fdf *fdf)
{
	fdf->cam[0].x = fdf->p_win.sx / 2;
	fdf->cam[0].y = 5;
	fdf->cam[0].z = -5;
	fdf->cam[0].rx = 0;
	fdf->cam[0].ry = 0;
	fdf->cam[0].rz = 16;
}

static int	load_imgs(t_fdf *fdf)
{
	int		x;

	x = 0;
	while (x < MAXP)
	{
		if (!(fdf->img[x] = mlx_new_image(fdf->mlx,
						fdf->p_win.sx, fdf->p_win.sy)))
			return (-1);
		x++;
	}
	return (0);
}

static int	load_all(void *mlx, t_fdf *fdf, int winnb, char **winname)
{
	size_t	v;

	v = -1;
	while (++v < winnb - 1)
	{
		if (!(fdf[v].map = parse_file(winname[v + 1])))
		{
			ft_printf("Could not open file %s\n", winname[v + 1]);
			fdf[v].win = NULL;
		}
		else
		{
			fdf[v].mlx = mlx;
			fdf[v].p_win.sx = WINX;
			fdf[v].p_win.sy = WINY;
			fdf[v].p_win.nb = v;
			fdf[v].cp = 0;
			basic_cam(&(fdf[v]));
			fdf[v].p_win.title = winname[v + 1];
			if (!(fdf[v].win = mlx_new_window(mlx, fdf[v].p_win.sx,
							fdf[v].p_win.sy, winname[v + 1])))
				return (-1);
			if (load_imgs(&(fdf[v])) != 0)
				return (-1);
		}
	}
	return (0);
}

t_fdf		*init_mlx(int winnb, char **winname)
{
	t_fdf	*fdf;
	void	*mlx;

	if (winnb < 2)
		return (NULL);
	if (!(fdf = malloc(sizeof(t_fdf) * winnb)))
		return (NULL);
	fdf[winnb - 1].mlx = NULL;
	if (!(mlx = mlx_init()))
		return (NULL);
	load_all(mlx, fdf, winnb, winname);
	return (fdf);
}
