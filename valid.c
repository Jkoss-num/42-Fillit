/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/17 16:23:07 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/25 01:38:54 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>
#include <stdio.h>

int		one_tetro(const int fd, char *line)
{
	int four_line;
	int i;

	four_line = 0;
	i = 0;
	while (four_line < 4)
	{
		if (get_next_line(fd, &line))
		{
			i = i + block_count(line);
			if (check_block(line) == 0 || ft_strlen(line) != 4)
			{
				write(1, "error\n", 6);
				exit(1);
			}
			free(line);
		}
		four_line++;
	}
	if (i != 4)
	{
		write(1, "error\n", 6);
		exit(1);
	}
	return (1);
}

int		block_count(char *line)
{
	int i;

	i = 0;
	if (!line)
		return (0);
	while (*line)
	{
		if (*line == '#')
		{
			i++;
		}
		line++;
	}
	return (i);
}

int		check_block(char *point)
{
	while (*point)
	{
		if (*point != '#' && *point != '.')
			return (0);
		point++;
	}
	return (1);
}

int		validate(const int fd)
{
	char	*line;
	int		i;

	i = 0;
	line = NULL;
	while (1)
	{
		one_tetro(fd, line);
		if ((get_next_line(fd, &line)) == 0)
			break ;
		if (ft_strlen(line) != 0)
		{
			write(1, "error\n", 6);
			exit(1);
		}
		free(line);
		i++;
	}
	if (i > 25)
		type_error();
	close(fd);
	return (1);
}
