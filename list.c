/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: otiffiny <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/23 20:13:56 by otiffiny          #+#    #+#             */
/*   Updated: 2019/12/23 20:14:45 by otiffiny         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_fillit	*first_list(void *tetro_type, char tetro_letter)
{
	t_fillit *elem;

	elem = (t_fillit *)malloc(sizeof(t_fillit));
	elem->tetro_type = tetro_type;
	elem->letter = tetro_letter;
	elem->next = NULL;
	return (elem);
}

t_fillit	*next_list(void *tetro_type, t_fillit *first, char letter)
{
	t_fillit *current;
	t_fillit *elem;

	current = first;
	while (current->next != NULL)
		current = current->next;
	elem = first_list(tetro_type, letter);
	current->next = elem;
	return (first);
}

void		free_list(t_fillit *coord)
{
	t_fillit *i;

	while (coord)
	{
		i = coord;
		coord = i->next;
		free(i);
	}
}

void		free_end(t_fillit *coord)
{
	t_fillit *i;

	while (coord)
	{
		i = coord;
		coord = i->next;
		free(i->tetro_type);
		free(i);
	}
}
