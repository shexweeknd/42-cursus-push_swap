/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:59:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/01 14:58:47 by hramaros         ###   ########.fr       */
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

t_pile	*init_pile(void)
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
	first_elem->target = NULL;
	first_elem->cost = 0;
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
		elem->next = init_pile();
		elem->next->prev = elem;
		*elem->next->value = number;
	}
	else if (current_cursor == 0)
		*elem->value = number;
	else if (current_cursor >= last_cursor)
		return (1);
	return (1);
}
