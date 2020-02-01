/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:22:09 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/24 19:33:05 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		collision_solve(char **square, int *tetro, t_fillit *coord, int size)
{
	if ((map_overlap(tetro, size) == 0) && (tetro_overlap(square, tetro) == 0))
	{
		move_letter(square, tetro, coord->letter);
		if (solution(square, coord->next, size))
		{
			free(tetro);
			return (1);
		}
		del_tetro(square, tetro);
	}
	return (0);
}

int		tetro_overlap(char **square, int *tetro)
{
	int size;
	int i;

	i = 0;
	size = 4;
	while (size--)
	{
		if (square[tetro[i + 1]][tetro[i]] != '.')
			return (1);
		i = i + 2;
	}
	return (0);
}

int		map_overlap(int *tetro, int size)
{
	int x;
	int y;
	int i;
	int len;

	i = 0;
	len = 3;
	x = tetro[i];
	while (len--)
	{
		i = i + 2;
		if (x < tetro[i])
			x = tetro[i];
	}
	i = 1;
	y = tetro[i];
	while (len++ < 2)
	{
		i = i + 2;
		if (y < tetro[i])
			y = tetro[i];
	}
	if (x >= size || y >= size)
		return (1);
	return (0);
}

void	move_letter(char **square, int *tetro, char letter)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		x = tetro[i];
		y = tetro[i + 1];
		square[y][x] = letter;
		i = i + 2;
	}
}

void	del_tetro(char **square, int *tab)
{
	int i;
	int x;
	int y;

	i = 0;
	x = 0;
	y = 0;
	while (i < 8)
	{
		y = tab[i + 1];
		x = tab[i];
		square[y][x] = '.';
		i = i + 2;
	}
}
