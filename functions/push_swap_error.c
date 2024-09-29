/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_error.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/14 14:11:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 14:11:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_has_greater_than(t_pile *pile, long long to_compare)
{
	while (pile)
	{
		if (*pile->value > to_compare)
			return (1);
		pile = pile->next;
	}
	return (0);
}

int	ft_has_duplicates(t_pile *pile)
{
	t_pile	*temp;
	t_pile	*greater_min;

	temp = pile;
	while (temp)
	{
		greater_min = temp->next;
		while (greater_min)
		{
			if (*temp->value == *greater_min->value)
				return (1);
			greater_min = greater_min->next;
		}
		temp = temp->next;
	}
	return (0);
}

int	ft_is_sorted(t_pile *pile)
{
	int	temp;

	temp = *pile->value;
	pile = pile->next;
	while (pile)
	{
		if (*pile->value < temp)
			return (0);
		temp = *pile->value;
		pile = pile->next;
	}
	return (1);
}
