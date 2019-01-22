/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:03:51 by magrab            #+#    #+#             */
/*   Updated: 2019/01/22 16:06:28 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

# define WINX 1000
# define WINY 1000

typedef struct	s_value{
	int x;
	int y;
	int z;
	int c;
}				t_value;

typedef struct	s_win{
	int		sizex;
	int		sizey;
	char	*title;
}				t_win;

typedef struct	s_cam{
	int		x;
	int		y;
	int		z;
	int		rx;
	int		ry;
	int		rz;
}				t_cam;

typedef struct	s_fdf{
	void	*mlx;
	void	*win;
	void	*img;
	char	*istr;
	t_win	p_win;
	t_cam	cam;
}				t_fdf;

/*
** void			*g_mlx(int setup);
** void			*g_win(t_win *win);
*/

int				key_press(int key, t_fdf *fdf);
int				key_release(int key, t_fdf *fdf);
int				mouse_hook(int button, int x, int y, t_fdf *fdf);
int				mouse_move(int x, int y, t_fdf *fdf);

void			draw_line(t_fdf *fdf, t_value pos0, t_value pos1);
void			test_draw(void *win, int x, int y);

t_value			*init_value(int x, int y, int z, int c);
t_fdf			*init_mlx(int winnb, char **winname);

int				drawmap(t_value **test, int dx, int dy, int space);
t_value			**calcmap(int setup);

#endif
