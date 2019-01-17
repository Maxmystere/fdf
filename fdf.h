/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:03:51 by magrab            #+#    #+#             */
/*   Updated: 2019/01/17 19:39:02 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>
#include "libft/libft.h"

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

void			*g_mlx(int setup);
void			*g_win(t_win *win);

int				key_hook(int key, void *param);
int				mouse_hook(int button, int x, int y, void *win);

void			draw_line(int x0, int y0, int x1, int y1);
void			test_draw(void *win, int x, int y);

t_value			*init_value(int x, int y, int z, int c);

int				drawmap(t_value **test, int dx, int dy, int space);
t_value			**calcmap(int setup);

#endif
