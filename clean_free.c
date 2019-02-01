/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean_free.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/29 18:02:23 by tferrieu          #+#    #+#             */
/*   Updated: 2019/02/01 17:36:12 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*
** clean_lst		: free every link in a t_list starting from the link given.
*/

void	clean_lst(t_list *lst)
{
	t_list *pos;
	t_list *tmp;

	pos = lst;
	while (pos)
	{
		if (pos->content)
			free(pos->content);
		tmp = pos;
		pos = pos->next;
		free(tmp);
	}
}

/*
** clean_3dtab		: free the memory used by a char ***.
*/

void	clean_3dtab(char ***tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_2dchar_free(tab + i++);
}

/*
** clean_postab		: free the memory used by the map resulting from the parsing
** of a fdf file.
*/

void	clean_postab(t_pos **tab)
{
	int i;

	i = 0;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}
