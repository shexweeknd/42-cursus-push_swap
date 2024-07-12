/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_debug_one.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:51:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 16:19:50 by hramaros         ###   ########.fr       */
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
