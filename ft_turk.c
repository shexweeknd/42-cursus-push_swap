/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:39:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/06 14:47:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_max_target_from_array(t_pile *pile, long *tab, int array_size)
{
	long	max;
	t_pile	*result;

	max = *tab;
	if (!array_size)
		return (NULL);
	while (array_size--)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	while (pile)
	{
		if (*pile->value == max)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

t_pile	*get_min_target_from_array(t_pile *pile, long *tab, int array_size)
{
	long	min;
	t_pile	*result;

	min = *tab;
	if (!array_size)
		return (NULL);
	while (array_size--)
	{
		if (*tab < min)
			min = *tab;
		tab++;
	}
	while (pile)
	{
		if (*pile->value == min)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

t_pile	*get_max_value_in(t_pile *pile)
{
	long	max;
	t_pile	*cursor;

	cursor = pile;
	max = *cursor->value;
	while (cursor)
	{
		if (*cursor->value > max)
			max = *cursor->value;
		cursor = cursor->next;
	}
	while (pile)
	{
		if (*pile->value == max)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

t_pile	*get_min_value_in(t_pile *pile)
{
	long	min;
	t_pile	*cursor;

	cursor = pile;
	min = *cursor->value;
	while (cursor)
	{
		if (*cursor->value < min)
			min = *cursor->value;
		cursor = cursor->next;
	}
	while (pile)
	{
		if (*pile->value == min)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

t_pile	*get_min_cost_in(t_pile *pile)
{
	int		min;
	t_pile	*cursor;

	cursor = pile;
	min = cursor->cost;
	while (cursor)
	{
		if (cursor->cost < min)
			min = cursor->cost;
		cursor = cursor->next;
	}
	while (pile)
	{
		if (pile->cost == min)
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}

int	set_a_target(t_pile **a, t_pile **b)
{
	t_pile	*curr_a;
	t_pile	*curr_b;
	long	*temp;
	int		index;

	if (!*a || !*b)
		return (-1);
	curr_a = *a;
	temp = malloc(sizeof(long) * get_pile_size(*b));
	if (!temp)
		return (free_pile(a), free_pile(b), -1);
	while (curr_a)
	{
		curr_b = *b;
		index = 0;
		ft_bezero(temp, get_pile_size(*b));
		while (curr_b)
		{
			if (*curr_b->value < *curr_a->value)
				temp[index++] = *curr_b->value;
			curr_b = curr_b->next;
		}
		curr_a->target = get_max_target_from_array(*b, temp, index);
		if (!curr_a->target)
			curr_a->target = get_max_value_in(*b);
		if (curr_a->target == NULL)
			return (free_pile(a), free_pile(b), free(temp), -1);
		curr_a = curr_a->next;
	}
	return (free(temp), 0);
}

/** todo remove 06 lines from code */
int	set_b_target(t_pile **a, t_pile **b)
{
	t_pile	*curr_a;
	t_pile	*curr_b;
	long	*temp;
	int		index;

	if (!*a || !*b)
		return (-1);
	curr_b = *b;
	temp = malloc(sizeof(long) * get_pile_size(*a));
	if (!temp)
		return (free_pile(a), free_pile(b), -1);
	while (curr_b)
	{
		curr_a = *a;
		index = 0;
		ft_bezero(temp, get_pile_size(*a));
		while (curr_a)
		{
			if (*curr_a->value > *curr_b->value)
				temp[index++] = *curr_a->value;
			curr_a = curr_a->next;
		}
		curr_b->target = get_min_target_from_array(*a, temp, index);
		if (!curr_b->target)
			curr_b->target = get_min_value_in(*a);
		if (curr_b->target == NULL)
			return (free_pile(a), free_pile(b), free(temp), -1);
		curr_b = curr_b->next;
	}
	return (free(temp), 0);
}

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
	int	pile_b_size;
	int	pile_a_size;

	pile_a_size = get_pile_size(a);
	pile_b_size = get_pile_size(b);
	while (a)
	{
		a->cost = ft_abs(a->index - pile_a_size) + ft_abs(a->target->index
				- pile_b_size);
		a = a->next;
	}
}

void	set_position(t_pile **pile, t_pile *target)
{
	int	pile_size;

	pile_size = get_pile_size(*pile);
	if (target->index > (pile_size / 2))
	{
		while (*pile != target)
			rrb(pile);
	}
	else
	{
		while (*pile != target)
			rb(pile);
	}
}
