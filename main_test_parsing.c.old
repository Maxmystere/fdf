/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test_parsing.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tferrieu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:38:19 by tferrieu          #+#    #+#             */
/*   Updated: 2019/02/08 14:51:23 by tferrieu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>
#include <fcntl.h>

int	main(int ac, char **av)
{
	int		x;
	int		y;
	t_pos	**map;

	(void)ac;
	if (!(map = parse_file(av[1])))
		return (write(1, "usage: ./a.out source_file\n", 27));
	if (!map)
		return (write(1, "Fichier incorrect\n", 18));
	x = 0;
	y = 0;
	printf("┌──");
	while (map[y][x].c >= 0)
	{
		printf("─────────");
		x++;
		if (map[y][x].c >= 0)
			printf("──┬──");
		else
			printf("──┐\n");
	}
	y = 0;
	while (map[y])
	{
		x = 0;
		printf("│  ");
		while (map[y][x].c >= 0)
		{
			printf("%d | %d | %d", map[y][x].x, map[y][x].z, map[y][x].y);
			x++;
			if (map[y][x].c >= 0)
				printf("  │  ");
			else
				printf("  │\n");
		}
		x = 0;
		printf("│  ");
		while (map[y][x].c >= 0)
		{
			printf("0x%06x", map[y][x].c);
			x++;
			if (map[y][x].c >= 0)
				printf("   │  ");
			else
				printf("   │\n");
		}
		x = 0;
		if (map[y + 1])
		{
			printf("├──");
			while (map[y][x].c >= 0)
			{
				printf("─────────");
				x++;
				if (map[y][x].c >= 0)
					printf("──┼──");
				else
					printf("──┤\n");
			}
		}
		y++;
	}
	x = 0;
	y = 0;
	printf("└──");
	while (map[y][x].c >= 0)
	{
		printf("─────────");
		x++;
		if (map[y][x].c >= 0)
			printf("──┴──");
		else
			printf("──┘\n");
	}
	clean_postab(map);
	return (0);
}
