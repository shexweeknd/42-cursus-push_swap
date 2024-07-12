/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   family_utils_two.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:22:11 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:48:19 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_family_id(t_pile *pile)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family > result)
			result = pile->family;
		pile = pile->next;
	}
	return (result);
}

int	is_family_set(t_pile *pile)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family != 0)
			result = 1;
		pile = pile->next;
	}
	return (result);
}

void	set_family_id(long value, t_pile *pile, int family_id)
{
	while (pile)
	{
		if (*pile->value == value)
			pile->family = family_id;
		pile = pile->next;
	}
}
