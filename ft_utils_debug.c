/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:51:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/09 14:57:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_targets(t_pile **pile)
{
	t_pile	*current;

	current = *pile;
	printf("targets:\n");
	while (current)
	{
		printf("%ld ==> %ld\n", *current->value, *current->target->value);
		current = current->next;
	}
}

void	print_costs(t_pile **pile)
{
	t_pile	*current;

	current = *pile;
	printf("cost:\n");
	while (current)
	{
		printf("%ld ==> %d\n", *current->value, current->target->cost);
		current = current->next;
	}
}

void	print_pile(t_pile **pile)
{
	t_pile	*first_elem;

	first_elem = *pile;
	while ((*pile))
	{
		printf("%ld\n", *(*pile)->value);
		*pile = (*pile)->next;
	}
	*pile = first_elem;
	return ;
}

void	print_families(t_pile **pile)
{
	t_pile	*first_elem;

	first_elem = *pile;
	while (*pile)
	{
		printf("%ld ==> family %d\n", *(*pile)->value, (*pile)->family);
		*pile = (*pile)->next;
	}
	*pile = first_elem;
	return ;
}

t_pile	*create_random_pile(size_t pile_size)
{
	t_pile	*pile;
	int		cursor;

	pile = init_pile(0);
	cursor = 0;
	while (cursor < pile_size)
	{
		if (cursor == 2)
		{
			ft_pileadd_back(pile, 0, cursor++, pile_size);
			continue ;
		}
		ft_pileadd_back(pile, cursor + 1, cursor++, pile_size);
	}
	return (pile);
}
