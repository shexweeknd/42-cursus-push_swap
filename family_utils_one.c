/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family_utils_one.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:05:56 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 16:39:43 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_family_to_b(int first_family_id, t_pile **a, t_pile **b)
{
	while (get_pile_size(*a) > 3 && is_family_set(*a))
	{
		if (get_pile_size(*a) == 4 && (*a)->family != 0)
		{
			pb(b, a);
			if ((*b)->family % 2 == 1)
				rb(b);
		}
		else if ((*a)->family == 0)
			ra(a);
		else if (((*a)->family > 0 && ((*a)->family % 2 == 0)) || !*b)
			pb(b, a);
		else if ((*a)->family > 0 && ((*a)->family % 2 == 1))
		{
			pb(b, a);
			if ((*a)->family == 0)
				rr(a, b);
			else
				rb(b);
		}
	}
}

int	is_any_fammemb(t_pile *pile, int id)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family == id)
			result = 1;
		pile = pile->next;
	}
	return (result);
}

int	get_numbers_of_family(t_pile **a)
{
	int	result;

	if (get_pile_size(*a) <= 100)
		result = 3;
	else
		result = 6;
	return (result);
}

void	set_family_subfunc(t_pile *pile, t_pile *first_elem, int max_members,
		int first_family_id)
{
	long	greater_min;
	long	last_min;
	int		members;

	last_min = *get_min_value_in(first_elem)->value;
	greater_min = *get_max_value_in(first_elem)->value;
	members = 1;
	while (members < (max_members * 2))
	{
		if ((*pile->value > last_min) && (*pile->value < greater_min))
			greater_min = *pile->value;
		pile = pile->next;
		if (!pile)
		{
			if (members < max_members)
				set_family_id(greater_min, first_elem, first_family_id);
			else if (members < (max_members * 2))
				set_family_id(greater_min, first_elem, first_family_id + 1);
			members++;
			last_min = greater_min;
			pile = first_elem;
			greater_min = *get_max_value_in(first_elem)->value;
		}
	}
}

// TODO enlever 5 lignes
void	set_family(t_pile *pile, int first_family_id, int max_members)
{
	t_pile	*first_elem;

	first_elem = pile;
	while (*pile->value == *get_min_value_in(first_elem)->value)
		pile = pile->next;
	get_min_value_in(first_elem)->family = first_family_id;
	set_family_subfunc(pile, first_elem, max_members, first_family_id);
}
