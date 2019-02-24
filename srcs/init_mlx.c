/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mlx.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/21 19:34:47 by magrab            #+#    #+#             */
/*   Updated: 2019/02/24 16:07:20 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

/*
** Put here initial camera value
*/

static void	basic_cam(t_fdf *fdf)
{
	int x;

	x = (fdf->p_m.x > 400 ? 1 : 400 / fdf->p_m.x);
	fdf->cam[ISO].x = fdf->p_win.sx / 2;
	fdf->cam[ISO].y = fdf->p_win.sy / 2;
	fdf->cam[ISO].z = -2;
	fdf->cam[ISO].rx = x * 2;
	fdf->cam[ISO].ry = x;
	fdf->cam[CARRE].x = fdf->p_win.sx / 2;
	fdf->cam[CARRE].y = fdf->p_win.sy / 2;
	fdf->cam[CARRE].z = -2;
	fdf->cam[CARRE].rx = x;
	fdf->cam[CARRE].ry = x;
	fdf->cam[FLAT].x = fdf->p_win.sx / 2;
	fdf->cam[FLAT].y = fdf->p_win.sy / 2;
	fdf->cam[FLAT].z = -2;
	fdf->cam[FLAT].rx = 20;
	fdf->cam[FLAT].ry = 40;
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

static void	short_load(void *mlx, t_fdf *fdf, size_t v)
{
	fdf[v].mlx = mlx;
	fdf[v].p_win.sx = WINX;
	fdf[v].p_win.sy = WINY;
	fdf[v].p_win.nb = v;
	fdf[v].cp = ISO;
	fdf[v].pr = 0;
	fdf[v].keys = NULL;
}

static int	load_all(void *mlx, t_fdf *fdf, int winnb, char **winname)
{
	int	v;
	int	winopened;

	v = -1;
	winopened = 0;
	while (++v < winnb - 1)
	{
		fdf[v].mlx = mlx;
		if (!(fdf[v].map = parse_file(winname[v + 1], &(fdf[v])))
														&& !(fdf[v].win = NULL))
			ft_printf("Could not open file %s\n", winname[v + 1]);
		else if (++winopened)
		{
			short_load(mlx, fdf, v);
			basic_cam(&(fdf[v]));
			fdf[v].p_win.title = winname[v + 1];
			if (!(fdf[v].win = mlx_new_window(mlx, fdf[v].p_win.sx,
							fdf[v].p_win.sy, winname[v + 1])))
				return (-1);
			if (load_imgs(&(fdf[v])) != 0)
				return (-1);
		}
	}
	return (winopened);
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
	if (load_all(mlx, fdf, winnb, winname) <= 0)
		exit(0);
	return (fdf);
}
