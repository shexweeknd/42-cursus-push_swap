/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_two.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:39:26 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:44:45 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_bezero(long *data, int pile_size)
{
	int	index;

	index = 0;
	while (index < pile_size)
	{
		data[index] = 0;
		index++;
	}
}

size_t	get_args_numbers(char *argv)
{
	size_t	result;
	int		index;

	result = 0;
	index = 0;
	while (argv[index])
	{
		if (argv[index] == 32)
			index++;
		else if (ft_isnumber(&argv[index]))
		{
			result++;
			index++;
		}
		else
			return (0);
	}
	return (result);
}

t_pile	*get_last_elem(t_pile *pile)
{
	if (!pile)
		return (NULL);
	while (pile->next != NULL)
	{
		pile = pile->next;
	}
	return (pile);
}
