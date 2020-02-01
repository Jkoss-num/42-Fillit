/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   size.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 23:17:58 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/23 20:21:58 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		count_tetro(t_fillit *coord)
{
	int			letter;
	t_fillit	*temp;

	temp = coord;
	letter = 0;
	while (temp != 0)
	{
		temp = temp->next;
		letter++;
	}
	return (letter);
}

int		calc_size(t_fillit *coord)
{
	int		k;
	int		size;

	size = 2;
	while ((k = (count_tetro(coord) * 4)) > (size * size))
		size++;
	return (size);
}

int		*t_type(char *type)
{
	int *tetro;

	tetro = (int *)malloc(sizeof(int) * 8);
	(ft_strcmp(type, "TETRO_1") == 0) && (coordcpy(tetro, TETRO_1));
	(ft_strcmp(type, "TETRO_2") == 0) && (coordcpy(tetro, TETRO_2));
	(ft_strcmp(type, "TETRO_3") == 0) && (coordcpy(tetro, TETRO_3));
	(ft_strcmp(type, "TETRO_4") == 0) && (coordcpy(tetro, TETRO_4));
	(ft_strcmp(type, "TETRO_5") == 0) && (coordcpy(tetro, TETRO_5));
	(ft_strcmp(type, "TETRO_6") == 0) && (coordcpy(tetro, TETRO_6));
	(ft_strcmp(type, "TETRO_7") == 0) && (coordcpy(tetro, TETRO_7));
	(ft_strcmp(type, "TETRO_8") == 0) && (coordcpy(tetro, TETRO_8));
	(ft_strcmp(type, "TETRO_9") == 0) && (coordcpy(tetro, TETRO_9));
	(ft_strcmp(type, "TETRO_10") == 0) && (coordcpy(tetro, TETRO_10));
	(ft_strcmp(type, "TETRO_11") == 0) && (coordcpy(tetro, TETRO_11));
	(ft_strcmp(type, "TETRO_12") == 0) && (coordcpy(tetro, TETRO_12));
	(ft_strcmp(type, "TETRO_13") == 0) && (coordcpy(tetro, TETRO_13));
	(ft_strcmp(type, "TETRO_14") == 0) && (coordcpy(tetro, TETRO_14));
	(ft_strcmp(type, "TETRO_15") == 0) && (coordcpy(tetro, TETRO_15));
	(ft_strcmp(type, "TETRO_16") == 0) && (coordcpy(tetro, TETRO_16));
	(ft_strcmp(type, "TETRO_17") == 0) && (coordcpy(tetro, TETRO_17));
	(ft_strcmp(type, "TETRO_18") == 0) && (coordcpy(tetro, TETRO_18));
	(ft_strcmp(type, "TETRO_19") == 0) && (coordcpy(tetro, TETRO_19));
	return (tetro);
}

int		coordcpy(int *dest, int *src)
{
	int i;

	i = -1;
	while (++i < 8)
		dest[i] = src[i];
	return (1);
}
