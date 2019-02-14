/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 17:18:53 by tferrieu          #+#    #+#             */
/*   Updated: 2019/02/14 14:06:02 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <fcntl.h>

/*
** scan_file		: used by parse_file to store all read lines into a t_list.
*/

static t_list	*scan_file(int fd)
{
	t_list	*list;
	t_list	*pos;
	char	*line;

	get_next_line(fd, &line);
	if (!(list = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	list->content = line;
	list->next = NULL;
	pos = list;
	while (get_next_line(fd, &line))
	{
		if (!(pos->next = (t_list *)malloc(sizeof(t_list))))
		{
			clean_lst(list);
			return (NULL);
		}
		pos = pos->next;
		pos->next = NULL;
		pos->content = line;
	}
	free(line);
	return (list);
}

/*
** split_lines		: used by parse_file to process the lines read by scan_file
** into a triple pointer tab (char ***).
*/

static char		***split_lines(t_list *list)
{
	char	***tab;
	t_list	*pos;
	int		c;

	c = 0;
	pos = list;
	while (pos && ++c)
		pos = pos->next;
	pos = list;
	if (!(tab = (char ***)malloc(sizeof(char **) * (c + 1))))
	{
		clean_lst(list);
		return (NULL);
	}
	c = 0;
	while (pos)
	{
		tab[c] = ft_strsplit(pos->content, ' ');
		pos = pos->next;
		c++;
	}
	clean_lst(list);
	tab[c] = NULL;
	return (tab);
}

/*
** process_line		: used by process_values to check if a given line resulting
** from split_lines is valid. If so, the values are processed and stored into a
** map (t_pos **). Requires a specified line length (len) as well as an int
** indicating the current line being analyzed (y).
*/

static t_map	*process_line(char **line, int len, int y)
{
	int		x;
	t_pos	*vline;

	if (!(vline = (t_pos *)malloc(sizeof(t_pos) * (len + 1))))
		return (NULL);
	x = 0;
	while (x < len && line[x])
	{
		vline[x].z = ft_atoi(line[x]);
		vline[x].c = 0xffffff;
		if (ft_strchr(line[x], ','))
			vline[x].c = ft_htoi(ft_strchr(line[x], ',') + 1) % 0x1000000;
		x++;
	}
	if (x < len)
		return (NULL);
	vline[x].c = -42;
	return (vline);
}

/*
** process_values	: used by parse_file to process the tab from split_lines
** into a map (t_pos **).
*/

static t_map	**process_values(char ***splitab, int nbl, int len)
{
	t_map	**tab_val;
	int		i;

	i = 0;
	tab_val = (t_pos **)malloc(sizeof(t_pos) * (nbl + 1));
	tab_val[nbl] = NULL;
	while (i < nbl)
	{
		if (!(tab_val[i] = process_line(splitab[i], len, i)))
		{
			clean_3dtab(splitab + i);
			clean_postab(tab_val);
			return (NULL);
		}
		ft_2dchar_free(splitab + i);
		i++;
	}
	free(splitab);
	return (tab_val);
}

/*
** parse_file		: parse the file indicated by the given file descriptor, and
** returns a map (t_pos **) compatible with fdf rendering utility.
*/

t_pos			**parse_file(char *filename, t_fdf *fdf)
{
	char	***splitab;
	int		x;
	int		y
	int		fd;

	if (!((fd = open(filename, O_RDONLY | O_DIRECTORY)) == -1 &&
				(fd = open(filename, O_RDONLY)) != -1))
		return (NULL);
	if (!(splitab = split_lines(scan_file(fd))))
		return (NULL);
	close(fd);
	y = 0;
	x = 0;
	while (splitab[y][x])
		x++;
	while (splitab[y])
		y++;
	fdf->p_m.x = x;
	fdf->p_m.y = y;
	return (process_values(splitab, y, x));
}
