/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pseudo_op_ab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:25 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/15 12:30:48 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pseudo_rr(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_ra(a);
	pseudo_rb(b);
}

void	pseudo_rrr(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_rra(a);
	pseudo_rrb(b);
}

void	pseudo_ss(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_sa(a);
	pseudo_sb(b);
}
