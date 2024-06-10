/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:25 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/10 11:52:25 by hramaros         ###   ########.fr       */
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
void	rr(t_pile **a, t_pile **b)
{
	ra(a);
	rb(b);
	write(1, "rr\n", 3);
}

/**
 * @brief  rra et rrb en même temps.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
void	rrr(t_pile **a, t_pile **b)
{
	rra(a);
	rrb(b);
	write(1, "rrr\n", 3);
}
