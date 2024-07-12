/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_turk_two.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:34:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:45:51 by hramaros         ###   ########.fr       */
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

t_pile	*get_min_cost_in(t_pile *pile, int family_id)
{
	int		min;
	t_pile	*cursor;

	cursor = pile;
	while (cursor->family != family_id)
		cursor = cursor->next;
	min = cursor->cost;
	while (cursor)
	{
		if (family_id == cursor->family && (cursor->cost < min))
			min = cursor->cost;
		cursor = cursor->next;
	}
	while (pile)
	{
		if (pile->cost == min && (pile->family == family_id))
			return (pile);
		pile = pile->next;
	}
	return (NULL);
}
