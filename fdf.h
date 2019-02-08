/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:03:51 by magrab            #+#    #+#             */
/*   Updated: 2019/02/08 14:55:30 by magrab           ###   ########.fr       */
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

/*
** Maximum number of projections
*/

# define ISO 0
# define MAXP 1

typedef struct	s_pos{
	int x;
	int y;
	int z;
	int c;
}				t_pos;

typedef struct	s_win{
	int		nb;
	int		sx;
	int		sy;
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

/*
** cp : Current projection
** 0 = Iso
** 1 = //
*/

typedef struct	s_fdf{
	void	*mlx;
	void	*win;
	t_pos	**map;
	int		cp;
	t_cam	cam[MAXP];
	void	*img[MAXP];
	int		*istr;
	int		bpp;
	int		s_l;
	int		e;
	t_win	p_win;
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
t_fdf			*init_mlx(int winnb, char **winname, t_pos **map);

void			*draw_iso(t_fdf *fdf, t_pos **tab, t_cam pos);
t_pos			**calcmap(int setup);

int				close_hook(t_fdf *fdf);

void			clean_lst(t_list *lst);

void			clean_3dtab(char ***splitab);

void			clean_postab(t_pos **tab);

t_pos			**parse_file(char *filename);

#endif
