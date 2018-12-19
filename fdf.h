/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 22:03:51 by magrab            #+#    #+#             */
/*   Updated: 2018/12/19 13:33:36 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include <stdlib.h>
# include <stdio.h>
# include <math.h>

void			*g_mlx(int setup);
void			*g_win(int win, int sizex, int sizey, char *win_name);

int				key_hook(int key, void *param);
int				mouse_hook(int button, int x, int y, void *win);

void			draw_line(int x0, int y0, int x1, int y1);
void			test_draw(void *win, int x, int y);

int				get_next_line(const int fd, char **line);

#endif
