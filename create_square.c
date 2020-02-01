/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_square.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/20 19:22:01 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/24 19:32:07 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*save_temp(const int fd, char *line)
{
	int				*tetro;
	char			*tetro_type;
	char			letter;
	t_fillit		*first;
	t_fillit		*elem;

	first = NULL;
	letter = 'A';
	while (1)
	{
		tetro = move_coord(read_one_tetro(fd, line));
		if (!(tetro_type = gettype(tetro)))
			type_error();
		if (first == NULL)
			first = first_list(tetro_type, letter++);
		else
			elem = next_list(tetro_type, first, letter++);
		free(tetro);
		if (!(get_next_line(fd, &line)))
			break ;
		free(line);
	}
	return (first);
}

t_fillit	*let_coord(t_fillit *coord)
{
	char		*tetro_type;
	char		letter;
	t_fillit	*first;
	t_fillit	*elem;

	first = NULL;
	letter = 'A';
	while (coord)
	{
		tetro_type = coord->tetro_type;
		if (first == NULL)
			first = first_list(t_type(tetro_type), letter++);
		else
			elem = next_list(t_type(tetro_type), first, letter++);
		coord = coord->next;
	}
	return (first);
}

char		**create_square(int size)
{
	int		i;
	char	**square;
	char	*line;

	i = -1;
	if ((square = (char **)malloc(sizeof(char *) * size + 1)) == NULL)
		return (NULL);
	while (++i < size)
	{
		square[i] = (char *)malloc(sizeof(char) * size + 1);
		line = create_line(size);
		ft_strcpy(square[i], line);
		free(line);
	}
	square[i] = NULL;
	return (square);
}

char		*create_line(int size)
{
	int		i;
	char	*line;

	i = -1;
	if ((line = (char *)malloc(sizeof(char) * size + 1)) == NULL)
		return (NULL);
	while ((++i) < size)
		line[i] = '.';
	line[i] = '\0';
	return (line);
}

void		free_square(char **square, int size)
{
	int i;

	i = 0;
	while (i < size)
	{
		ft_strdel(&square[i]);
		i++;
	}
	free(square);
}
