/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_movement.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: magrab <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 14:00:19 by magrab            #+#    #+#             */
/*   Updated: 2019/02/16 17:58:28 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** 18 : 1 key
** 19 : 2 key
** 20 : 3 key
** 21 : 4 key
** 53 : esc key
** 50 : key under esc
** 69 : plus numpad
** 78 : minus numpad
** 84 : num 2
** 91 : num 8
** 123 : left key
** 124 : right key
** 125 : down key
** 126 = up key
*/

t_cam	move_iso(t_fdf *fdf, int key)
{
	if (fdf->cp != ISO)
		return (fdf->cam[fdf->cp]);
	if (key == 69)
		fdf->cam[fdf->cp].z--;
	else if (key == 78)
		fdf->cam[fdf->cp].z++;
	else if (key == 84 && fdf->cam[fdf->cp].rx - 1 > 1)
	{
		fdf->cam[fdf->cp].rx -= ZOOMSPEED * 2;
		fdf->cam[fdf->cp].ry -= ZOOMSPEED;
	}
	else if (key == 91)
	{
		fdf->cam[fdf->cp].rx += ZOOMSPEED * 2;
		fdf->cam[fdf->cp].ry += ZOOMSPEED;
	}
	else if (key == 123)
		fdf->cam[fdf->cp].x -= CAMSPEED;
	else if (key == 124)
		fdf->cam[fdf->cp].x += CAMSPEED;
	else if (key == 125)
		fdf->cam[fdf->cp].y += CAMSPEED;
	else if (key == 126)
		fdf->cam[fdf->cp].y -= CAMSPEED;
	return (fdf->cam[fdf->cp]);
}

t_cam	move_carre(t_fdf *fdf, int key)
{
	if (fdf->cp != CARRE)
		return (fdf->cam[fdf->cp]);
	if (key == 69)
		fdf->cam[fdf->cp].z--;
	else if (key == 78)
		fdf->cam[fdf->cp].z++;
	else if (key == 84 && fdf->cam[fdf->cp].rx - 1 > 1)
	{
		fdf->cam[fdf->cp].rx -= ZOOMSPEED;
		fdf->cam[fdf->cp].ry -= ZOOMSPEED;
	}
	else if (key == 91)
	{
		fdf->cam[fdf->cp].rx += ZOOMSPEED;
		fdf->cam[fdf->cp].ry += ZOOMSPEED;
	}
	else if (key == 123)
		fdf->cam[fdf->cp].x -= CAMSPEED;
	else if (key == 124)
		fdf->cam[fdf->cp].x += CAMSPEED;
	else if (key == 125)
		fdf->cam[fdf->cp].y += CAMSPEED;
	else if (key == 126)
		fdf->cam[fdf->cp].y -= CAMSPEED;
	return (fdf->cam[fdf->cp]);
}

t_cam	move_flat(t_fdf *fdf, int key)
{
	if (fdf->cp != FLAT)
		return (fdf->cam[fdf->cp]);
	if (key == 69)
		fdf->cam[fdf->cp].z--;
	else if (key == 78)
		fdf->cam[fdf->cp].z++;
	else if (key == 84 && fdf->cam[fdf->cp].rx - 1 > 1)
	{
		fdf->cam[fdf->cp].rx -= ZOOMSPEED;
		fdf->cam[fdf->cp].ry -= ZOOMSPEED * 2;
	}
	else if (key == 91)
	{
		fdf->cam[fdf->cp].rx += ZOOMSPEED;
		fdf->cam[fdf->cp].ry += ZOOMSPEED * 2;
	}
	else if (key == 123)
		fdf->cam[fdf->cp].x -= CAMSPEED;
	else if (key == 124)
		fdf->cam[fdf->cp].x += CAMSPEED;
	else if (key == 125)
		fdf->cam[fdf->cp].y += CAMSPEED;
	else if (key == 126)
		fdf->cam[fdf->cp].y -= CAMSPEED;
	return (fdf->cam[fdf->cp]);
}

/*
** pr : Projection rotation (0 -> 3)
** cp : Current projection
** 0 = Iso
** 1 = Carre
** 2 = Flat
*/

t_fdf	*change_projection(t_fdf *fdf, int key)
{
	if (key == 18)
	{
		if (fdf->cp == 0)
			fdf->pr = (fdf->pr + 1 <= 3 ? fdf->pr + 1 : 0);
		fdf->cp = 0;
	}
	else if (key == 19)
	{
		if (fdf->cp == 1)
			fdf->pr = (fdf->pr + 1 <= 3 ? fdf->pr + 1 : 0);
		fdf->cp = 1;
	}
	else if (key == 20)
	{
		if (fdf->cp == 2)
			fdf->pr = (fdf->pr + 1 <= 0 ? fdf->pr + 1 : 0);
		fdf->cp = 2;
	}
	return (fdf);
}
