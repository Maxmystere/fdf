/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:03:51 by magrab            #+#    #+#             */
/*   Updated: 2019/01/24 18:15:24 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
# include "libft/libft.h"

# define WINX 500
# define WINY 500

typedef struct	s_value{
	int x;
	int y;
	int z;
	int c;
}				t_pos;

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
	t_pos	**map;
	void	*img;
	char	*istr;
	int		bpp;
	int		size_line;
	int		endian;
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

void			fill_pixel(t_fdf *fdf, int x, int y, int color);
void			fill_line(t_fdf *fdf, t_pos pos0, t_pos pos1);
void			draw_line(t_fdf *fdf, t_pos pos0, t_pos pos1);
void			test_draw(t_fdf *fdf, int x, int y);

t_pos			*init_value(int x, int y, int z, int c);
t_fdf			*init_mlx(int winnb, char **winname);

void			*draw_map(t_fdf *fdf, t_pos **tab, t_cam pos);
t_pos			**calcmap(int setup);

#endif
