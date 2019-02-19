/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlxmain.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 16:32:14 by tferrieu          #+#    #+#             */
/*   Updated: 2019/02/19 20:58:05 by magrab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static void		draw_boussole(t_fdf *fdf, int x, int y)
{
	if (fdf->pr % 2 == 0)
	{
		mlx_string_put(fdf->mlx, fdf->win, x - 5, y - 10, (fdf->pr == 0 ?
												0xF44141 : 0xFFFFFF), "/\\");
		mlx_string_put(fdf->mlx, fdf->win, x - 5, y + 10, (fdf->pr == 0 ?
												0xFFFFFF : 0xF44141), "\\/");
	}
	else if (fdf->pr % 2)
	{
		mlx_string_put(fdf->mlx, fdf->win, x + 10, y + 2, (fdf->pr == 1 ?
												0xF44141 : 0xFFFFFF), ">");
		mlx_string_put(fdf->mlx, fdf->win, x - 10, y + 2, (fdf->pr == 1 ?
												0xFFFFFF : 0xF44141), "<");
	}
	mlx_string_put(fdf->mlx, fdf->win, x, y, 0xFFFFFF, "o");
}

static void		draw_more(t_fdf *fdf, int x,int y)
{
	char	*tmp;
	char	*nbstr;
	int		rx;
	int		ry;

	rx = fdf->cam[fdf->cp].rx;
	ry = fdf->cam[fdf->cp].ry;
	nbstr = ft_itoa(rx <= ry ? rx : ry);
	tmp = ft_strjoin("Zoom : ", nbstr);
	mlx_string_put(fdf->mlx, fdf->win, 50, y + 75, 0xf44336, tmp);
	free(nbstr);
	free(tmp);
	(void)x;
}

void			draw_text(t_fdf *fdf, int x, int y)
{
	char *tmp;
	char *nbstr;

	draw_order(fdf, fdf->p_win.sx - 50, fdf->p_win.sy - 50, 0x500b00);
	draw_order(fdf, fdf->p_win.sx - 49, fdf->p_win.sy - 49, 0xff6950);
	draw_order(fdf, fdf->p_win.sx - 49, fdf->p_win.sy - 50, 0xff6950);
	draw_order(fdf, fdf->p_win.sx - 50, fdf->p_win.sy - 49, 0xff6950);
	draw_boussole(fdf, x, y);
	nbstr = ft_itoa(fdf->p_m.x);
	tmp = ft_strjoin("X : ", nbstr);
	mlx_string_put(fdf->mlx, fdf->win, 50, y, 0xf44336, tmp);
	free(nbstr);
	free(tmp);
	nbstr = ft_itoa(fdf->p_m.y);
	tmp = ft_strjoin("Y : ", nbstr);
	mlx_string_put(fdf->mlx, fdf->win, 50, y + 25, 0xf44336, tmp);
	free(nbstr);
	free(tmp);
	nbstr = ft_itoa(-fdf->cam[fdf->cp].z);
	tmp = ft_strjoin("Z : ", nbstr);
	mlx_string_put(fdf->mlx, fdf->win, 50, y + 50, 0xf44336, tmp);
	free(nbstr);
	free(tmp);
	draw_more(fdf, x, y);
}

void			show_menu(t_fdf *fdf)
{
	int y;

	y = fdf->p_win.sy - 60;
	mlx_string_put(fdf->mlx, fdf->win, 15, y - 213, 0x7f8c8d,
								"_______________________________________");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 192, 0xe74c3c, "   Tutorial");
	mlx_string_put(fdf->mlx, fdf->win, 15, y - 185, 0x7f8c8d,
								"_______________________________________");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 160, 0xFFFFFF,
								"   Change Projection : 1, 2, 3");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 140, 0xFFFFFF,
								"   Press current Projection to rotate");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 120, 0xFFFFFF,
								"   Move : Arrow Keys or Mouse Press");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 100, 0xFFFFFF,
								"   Change Altitude : + / -");
	mlx_string_put(fdf->mlx, fdf->win, 10, y - 80, 0xFFFFFF,
								"   Zoom in/out : 8 / 2 (NUMPAD)");
	mlx_string_put(fdf->mlx, fdf->win, 40, y - 60, 0xFFFFFF, "Show Menu : M");
	mlx_string_put(fdf->mlx, fdf->win, 40, y - 20, 0xbdc3c7, "Quit : Esc");
	mlx_string_put(fdf->mlx, fdf->win, 15, y - 8, 0x7f8c8d,
								"_______________________________________");
	while ((y -= 17) > fdf->p_win.sy - 265)
		mlx_string_put(fdf->mlx, fdf->win, 10, y + 5, 0x7f8c8d,
								"|                                      |");
}

int				main(int ac, char **av)
{
	t_fdf	*fdf;
	int		x;

	if (!(fdf = init_mlx(ac, av)))
		return (-1);
	x = -1;
	mlx_do_key_autorepeatoff(fdf->mlx);
	while (++x < ac - 1)
	{
		if (fdf[x].win)
		{
			draw_tilt(&(fdf[x]), fdf[x].map, fdf[x].cam[0]);
			show_menu(&(fdf[x]));
			mlx_hook(fdf[x].win, 2, 0, key_press, &(fdf[x]));
			mlx_hook(fdf[x].win, 3, 0, key_release, &(fdf[x]));
			mlx_hook(fdf[x].win, 4, 0, mouse_press, &(fdf[x]));
			mlx_hook(fdf[x].win, 5, 0, mouse_release, &(fdf[x]));
			mlx_hook(fdf[x].win, 6, 0, mouse_move, &(fdf[x]));
			mlx_hook(fdf[x].win, 17, 0, close_hook, &(fdf[x]));
		}
	}
	mlx_loop_hook(fdf->mlx, loop_hook, fdf);
	if (ac > 1)
		mlx_loop(fdf[0].mlx);
	return (0);
}
