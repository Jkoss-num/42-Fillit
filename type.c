/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   type.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:22:33 by otiffiny          #+#    #+#             */
/*   Updated: 2020/02/02 01:40:47 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	*gettype(int *tetro)
{
	char *type;

	type = NULL;
	(tabcmp(tetro, TETRO_1, sizeof(tetro))) && (type = "TETRO_1");
	(tabcmp(tetro, TETRO_2, sizeof(tetro))) && (type = "TETRO_2");
	(tabcmp(tetro, TETRO_3, sizeof(tetro))) && (type = "TETRO_3");
	(tabcmp(tetro, TETRO_4, sizeof(tetro))) && (type = "TETRO_4");
	(tabcmp(tetro, TETRO_5, sizeof(tetro))) && (type = "TETRO_5");
	(tabcmp(tetro, TETRO_6, sizeof(tetro))) && (type = "TETRO_6");
	(tabcmp(tetro, TETRO_7, sizeof(tetro))) && (type = "TETRO_7");
	(tabcmp(tetro, TETRO_8, sizeof(tetro))) && (type = "TETRO_8");
	(tabcmp(tetro, TETRO_9, sizeof(tetro))) && (type = "TETRO_9");
	(tabcmp(tetro, TETRO_10, sizeof(tetro))) && (type = "TETRO_10");
	(tabcmp(tetro, TETRO_11, sizeof(tetro))) && (type = "TETRO_11");
	(tabcmp(tetro, TETRO_12, sizeof(tetro))) && (type = "TETRO_12");
	(tabcmp(tetro, TETRO_13, sizeof(tetro))) && (type = "TETRO_13");
	(tabcmp(tetro, TETRO_14, sizeof(tetro))) && (type = "TETRO_14");
	(tabcmp(tetro, TETRO_15, sizeof(tetro))) && (type = "TETRO_15");
	(tabcmp(tetro, TETRO_16, sizeof(tetro))) && (type = "TETRO_16");
	(tabcmp(tetro, TETRO_17, sizeof(tetro))) && (type = "TETRO_17");
	(tabcmp(tetro, TETRO_18, sizeof(tetro))) && (type = "TETRO_18");
	(tabcmp(tetro, TETRO_19, sizeof(tetro))) && (type = "TETRO_19");
	return (type);
}

int		tabcmp(int *s1, int *s2, int n)
{
	int i;

	i = 0;
	while (i < n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}

void	type_error(void)
{
	write(1, "error\n", 6);
	exit(1);
}
