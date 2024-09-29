/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ab.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:25 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/15 12:31:40 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rr(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_ra(a);
	pseudo_rb(b);
	write(1, "rr\n", 3);
}

void	rrr(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_rra(a);
	pseudo_rrb(b);
	write(1, "rrr\n", 4);
}

void	ss(t_pile **a, t_pile **b)
{
	if (!*a || !*b)
		return ;
	pseudo_sa(a);
	pseudo_sb(b);
	write(1, "ss\n", 3);
}
