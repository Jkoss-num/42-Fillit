/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/04 14:29:33 by otiffiny          #+#    #+#             */
/*   Updated: 2020/02/02 01:40:47 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		main(int argc, char *argv[])
{
	int	fd;

	if (argc == 2)
	{
		fd = open(argv[1], O_RDONLY);
		if (fd > 0)
		{
			if (validate(fd))
			{
				fd = open(argv[1], O_RDONLY);
				solver(fd);
			}
		}
	}
	else if (argc != 2)
	{
		write(1, "usage: ./fillit [file name] source file\n", 41);
		exit(0);
	}
	else
	{
		write(1, "error\n", 6);
		exit(1);
	}
	close(fd);
}

int		solver(int fd)
{
	int			size;
	char		**square;
	t_fillit	*temp;
	t_fillit	*coord;

	temp = save_temp(fd, NULL);
	size = calc_size(temp);
	coord = let_coord(temp);
	square = create_square(size);
	while (!solution(square, coord, size))
	{
		free_square(square, size);
		size = size + 1;
		square = create_square(size);
	}
	print_answer(square, size);
	free_list(temp);
	free_end(coord);
	return (1);
}
