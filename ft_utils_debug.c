/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:51:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 08:48:56 by hramaros         ###   ########.fr       */
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
		printf("%ld ==> cost %d\n", *current->value, current->cost);
		current = current->next;
	}
}

void	print_index(t_pile **pile)
{
	t_pile	*current;

	current = *pile;
	printf("index:\n");
	while (current)
	{
		printf("%ld ==> index %d\n", *current->value, current->index);
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
	printf("families:\n");
	while (*pile)
	{
		printf("%ld ==> family %d\n", *(*pile)->value, (*pile)->family);
		*pile = (*pile)->next;
	}
	*pile = first_elem;
	return ;
}

void	print_one_elem(t_pile *pile)
{
	printf("The elem to push is :\n");
	printf("value: %ld\n", *pile->value);
	printf("index position: %d\n", pile->index);
	printf("cost: %d\n", pile->cost);
	printf("family: %d\n", pile->family);
	printf("target value: %ld\n", *pile->target->value);
	printf("prev value: %ld\n", *pile->prev->value);
	printf("next value: %ld\n", *pile->next->value);
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
