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

t_pile	*get_target_from_array(t_pile *pile, long *tab)
{
	long	max;
	t_pile	*result;

	max = -1;
	if (!*tab)
		return (NULL);
	while (*tab)
	{
		if (*tab > max)
			max = *tab;
		tab++;
	}
	if (max >= 0)
		while (pile)
		{
			if (*pile->value == max)
				return (pile);
			pile = pile->next;
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
		while (pile)
		{
			if (*pile->value == max)
				return (pile);
			pile = pile->next;
		}
	return (NULL);
}

void	set_a_target(t_pile **a, t_pile **b)
{
	t_pile	*curr_a;
	t_pile	*curr_b;
	long	*temp;
	int		index;

	if (!*a || !*b)
		return ;
	curr_a = *a;
	temp = malloc(sizeof(long) * get_pile_size(curr_b));
	if (!temp)
	{
		free_pile(a);
		free_pile(b);
		return ;
	}
	while (curr_a)
	{
		curr_b = *b;
		index = 0;
		while (curr_b)
		{
			if (*curr_b->value < *curr_a->value)
				temp[index] = *curr_b->value;
			curr_b = curr_b->next;
			index++;
		}
		// mettre dans target de curr_a l'adresse de celui qui a la valeur < curr_value mais aussi
		curr_a->target = get_target_from_array(*b, temp);
		if (!curr_a->target)
			curr_a->target = get_max_in(*b);
		if (curr_a->target == NULL)
		{
			free_pile(a);
			free_pile(b);
			free(temp);
			return ;
		}
		curr_a = curr_a->next;
	}
	free(temp);
}

void	set_a_target(t_pile **a, t_pile **b);