/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 11:39:58 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/01 14:16:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pile	*get_target_from_array(t_pile *pile, long *tab, int array_size)
{
	long	max;
	t_pile	*result;

	max = -1;
	if (!array_size)
		return (NULL);
	while (array_size--)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	if (max >= 0)
	{
		while (pile)
		{
			if (*pile->value == max)
				return (pile);
			pile = pile->next;
		}
	}
	return (NULL);
}

t_pile	*get_max_in(t_pile *pile)
{
	long	max;
	t_pile	*cursor;

	cursor = pile;
	max = -1;
	while (cursor)
	{
		if (*cursor->value > max)
			max = *cursor->value;
		cursor = cursor->next;
	}
	if (max >= 0)
	{
		while (pile)
		{
			if (*pile->value == max)
				return (pile);
			pile = pile->next;
		}
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
		curr_a->target = get_target_from_array(*b, temp, get_pile_size(*b));
		if (!curr_a->target)
			curr_a->target = get_max_in(*b);
		if (curr_a->target == NULL)
			return (free_pile(a), free_pile(b), free(temp), -1);
		curr_a = curr_a->next;
	}
	return (free(temp), -1);
}

int		set_b_target(t_pile **a, t_pile **b);