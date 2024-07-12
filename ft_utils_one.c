/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_one.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:59:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:44:44 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief retourne la taille de la pile
 *
 * @param pile
 * @return size_t
 * @date 2024-06-10
 */
size_t	get_pile_size(t_pile *pile)
{
	size_t	result;

	result = 0;
	while (pile)
	{
		result++;
		pile = pile->next;
	}
	return (result);
}

void	free_pile(t_pile **pile)
{
	t_pile	*suivant;
	t_pile	**sauvegarde;

	sauvegarde = pile;
	while (*pile)
	{
		suivant = (*pile)->next;
		free((*pile)->value);
		free(*pile);
		*pile = suivant;
	}
	return (free(sauvegarde));
}

t_pile	*init_pile(long value)
{
	t_pile	*first_elem;

	first_elem = (t_pile *)malloc(sizeof(t_pile));
	if (!first_elem)
		return (NULL);
	first_elem->next = NULL;
	first_elem->prev = NULL;
	first_elem->value = (long *)malloc(sizeof(long));
	if (!first_elem->value)
		return (free(first_elem), NULL);
	*first_elem->value = value;
	first_elem->target = NULL;
	first_elem->index = 0;
	first_elem->cost = 0;
	first_elem->family = 0;
	return (first_elem);
}

/**
 * @brief TODO debug pour prendre en compte number = 0
 *
 * @param elem
 * @param number
 * @return int
 * @date 2024-06-08
 */
int	ft_pileadd_back(t_pile *elem, long number, int current_cursor,
		int last_cursor)
{
	while (elem)
	{
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	if (current_cursor && (current_cursor < last_cursor))
	{
		elem->next = init_pile(0);
		elem->next->prev = elem;
		*elem->next->value = number;
	}
	else if (current_cursor == 0)
		*elem->value = number;
	else if (current_cursor >= last_cursor)
		return (1);
	return (1);
}

void	ft_pile_delfirst(t_pile **a)
{
	t_pile	*first_elem_a;
	t_pile	*second_elem_a;

	first_elem_a = *a;
	second_elem_a = (*a)->next;
	second_elem_a->prev = NULL;
	free(first_elem_a->value);
	free(first_elem_a);
	*a = second_elem_a;
}
