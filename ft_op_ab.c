/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:25 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/05 09:03:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief  ra et rb en même temps.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*rr(t_pile *first_elem)
{
	t_pile	*result;

	result = ra(first_elem);
	result = rb(result);
	return (result);
}

/**
 * @brief  rra et rrb en même temps.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*rrr(t_pile *first_elem)
{
	t_pile *result;

	result = rra(first_elem);
	result = rrb(result);

	return (result);
}