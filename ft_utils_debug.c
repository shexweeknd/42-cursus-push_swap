/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_debug.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:51:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/01 16:50:00 by hramaros         ###   ########.fr       */
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

t_pile	*create_random_pile(size_t pile_size)
{
	t_pile	*pile;
	int		total_pile_size;

	pile = init_pile();
	total_pile_size = 7;
	while (pile_size < total_pile_size)
		ft_pileadd_back(pile, (getpid() * pile_size) % 100, pile_size++,
			total_pile_size);
	return (pile);
}
