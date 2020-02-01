/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   backtr.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/22 01:50:17 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/24 19:32:07 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <unistd.h>

int		solution(char **square, t_fillit *coord, int size)
{
	int x;
	int y;
	int *tetro;

	y = -1;
	tetro = (int *)malloc(sizeof(int) * 8);
	if (!coord)
	{
		free(tetro);
		return (1);
	}
	while (++y < size)
	{
		x = -1;
		while (++x < size)
		{
			coordcpy(tetro, coord->tetro_type);
			move_tetro(tetro, x, y);
			if (collision_solve(square, tetro, coord, size))
				return (1);
		}
	}
	free(tetro);
	return (0);
}

int		*move_tetro(int *tetro, int x, int y)
{
	int size;
	int i;

	size = 4;
	i = 0;
	while (size--)
	{
		tetro[i] = tetro[i] + x;
		i = i + 2;
	}
	i = 1;
	while (size++ < 3)
	{
		tetro[i] = tetro[i] + y;
		i = i + 2;
	}
	return (tetro);
}

void	print_answer(char **square, int size)
{
	int	i;
	int k;

	i = -1;
	k = 0;
	while (square[++i])
	{
		ft_putstr(square[i]);
		write(1, "\n", 1);
	}
	while (k < size)
	{
		ft_strdel(&square[k]);
		k++;
	}
	free(square);
}
