/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:22:20 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/24 19:32:07 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		*move_coord(int *link)
{
	int size;
	int x;
	int y;
	int i;

	i = 0;
	size = 4;
	x = define_x(link);
	y = define_y(link);
	while (size--)
	{
		link[i] -= x;
		link[i + 1] -= y;
		i = i + 2;
	}
	return (link);
}

int		define_x(int *link)
{
	int size;
	int x;
	int i;

	i = 0;
	size = 4;
	x = link[i];
	while (size--)
	{
		if (link[i] >= 0 && link[i] <= 3)
		{
			if (link[i] < x)
			{
				x = link[i];
			}
		}
		i = i + 2;
	}
	return (x);
}

int		define_y(int *link)
{
	int size;
	int y;
	int i;

	i = 1;
	size = 4;
	y = link[i];
	while (size--)
	{
		if (link[i] >= 0 && link[i] <= 3)
		{
			if (link[i] < y)
			{
				y = link[i];
			}
		}
		i = i + 2;
	}
	return (y);
}

int		*read_one_tetro(const int fd, char *line)
{
	int		*link;
	int		i;
	int		x;
	int		y;

	y = 0;
	i = 0;
	link = (int *)malloc(sizeof(int) * 8);
	while (y++ < 4)
	{
		x = 0;
		get_next_line(fd, &line);
		while (line[x])
		{
			if (line[x] == '#')
			{
				link[i] = x;
				link[i + 1] = y;
				i = i + 2;
			}
			x++;
		}
		free(line);
	}
	return (link);
}
