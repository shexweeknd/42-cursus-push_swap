/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:18:28 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 14:24:05 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief trie la liste de 3 elements
 *
 * @param a
 * @date 2024-06-11
 */
void	mini_sort(t_pile **a)
{
	long	premier;
	long	deuxieme;
	long	troisieme;

	while (!ft_is_sorted(*a))
	{
		premier = *(*a)->value;
		deuxieme = *(*a)->next->value;
		troisieme = *(*a)->next->next->value;
		if ((troisieme > premier) && (troisieme > deuxieme))
			sa(a);
		else if ((premier > deuxieme) && (premier > troisieme))
			ra(a);
		else if ((deuxieme > premier) && (deuxieme > troisieme))
			rra(a);
	}
	free_pile(a);
}

void	put_in_b(t_pile **a, t_pile **b)
{
	int	chunk_size;
	int	last_family_id;

	last_family_id = 1;
	while (get_pile_size(*a) > 3)
	{
		chunk_size = get_pile_size(*a) / get_numbers_of_family(a);
		set_family(*a, last_family_id, chunk_size);
		push_family_to_b(last_family_id, a, b);
		last_family_id += 2;
	}
}

void	send_back_to_a(t_pile **a, t_pile **b)
{
	int	family_to_push;

	family_to_push = get_max_family_id(*b);
	while (*b != NULL)
	{
		while (!is_any_fammemb(*b, family_to_push))
			family_to_push--;
		set_b_target(a, b);
		set_index(a);
		set_index(b);
		set_costs(*a, *b);
		set_position(b, get_min_cost_in(*b, family_to_push));
		while ((*b)->target != *a)
		{
			set_index(a);
			if ((*b)->target->index > (get_pile_size(*a) / 2))
				rra(a);
			else
				ra(a);
		}
		pa(a, b);
	}
}

void	last_round(t_pile **a, t_pile *min)
{
	while (*a != min)
	{
		set_index(a);
		if (min->index > (get_pile_size(*a) / 2))
			rra(a);
		else
			ra(a);
	}
}
