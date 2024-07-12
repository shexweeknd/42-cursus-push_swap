/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_debug_two.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 16:19:04 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 16:20:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
