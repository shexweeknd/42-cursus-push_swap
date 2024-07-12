/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_one.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:39:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 16:43:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	set_index(t_pile **pile)
{
	int		i;
	t_pile	*curr;

	curr = *pile;
	if (!curr)
		return (-1);
	i = 1;
	while (curr)
	{
		curr->index = i++;
		curr = curr->next;
	}
	return (0);
}

void	set_costs(t_pile *a, t_pile *b)
{
	int	pile_a_size;
	int	pile_b_size;
	int	b_cost;
	int	b_target_cost;

	pile_b_size = get_pile_size(b);
	pile_a_size = get_pile_size(a);
	while (b)
	{
		b_target_cost = b->target->index;
		b_cost = b->index;
		if (b->index > (pile_b_size / 2))
			b_cost = ft_abs(pile_b_size - b->index) + 1;
		if (b->target->index <= (pile_a_size / 2))
			b_target_cost--;
		else if (b->target->index > (pile_a_size / 2))
			b_target_cost = ft_abs(pile_a_size - b->target->index) + 1;
		b->cost = b_cost + b_target_cost;
		b = b->next;
	}
}

int	set_position(t_pile **pile, t_pile *to_put_in_top)
{
	int	pile_size;

	pile_size = get_pile_size(*pile);
	if (to_put_in_top->index > (pile_size / 2))
	{
		while (*pile != to_put_in_top)
			rrb(pile);
	}
	else
	{
		while (*pile != to_put_in_top)
			rb(pile);
	}
	return (1);
}

int	fullfill_temp(t_pile *curr_a, t_pile *curr_b, long *temp)
{
	int	index;

	index = 0;
	while (curr_a)
	{
		if (*curr_a->value > *curr_b->value)
			temp[index++] = *curr_a->value;
		curr_a = curr_a->next;
	}
	return (index);
}

int	set_b_target(t_pile **a, t_pile **b)
{
	t_pile	*curr_a;
	t_pile	*curr_b;
	long	*temp;
	int		index;

	curr_b = *b;
	temp = malloc(sizeof(long) * get_pile_size(*a));
	if (!temp)
		return (free_pile(a), free_pile(b), -1);
	while (curr_b)
	{
		curr_a = *a;
		ft_bezero(temp, get_pile_size(*a));
		index = fullfill_temp(curr_a, curr_b, temp);
		curr_b->target = get_min_target_from_array(*a, temp, index);
		if (!curr_b->target)
			curr_b->target = get_min_value_in(*a);
		curr_b = curr_b->next;
	}
	return (free(temp), 0);
}
