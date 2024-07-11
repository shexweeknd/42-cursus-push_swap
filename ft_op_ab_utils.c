/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_ab_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 14:17:35 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/11 14:20:29 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pseudo_ra(t_pile **a)
{
	t_pile	*sauvegarde;
	t_pile	*return_adress;

	sauvegarde = *a;
	if (sauvegarde->next)
		return_adress = sauvegarde->next;
	else
		return_adress = sauvegarde;
	while (*a)
	{
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
	}
	(*a)->next = sauvegarde;
	sauvegarde->next->prev = NULL;
	sauvegarde->prev = *a;
	sauvegarde->next = NULL;
	*a = return_adress;
}

void	pseudo_rb(t_pile **b)
{
	t_pile	*sauvegarde;
	t_pile	*return_adress;

	sauvegarde = *b;
	if (sauvegarde->next)
		return_adress = sauvegarde->next;
	else
		return_adress = sauvegarde;
	while (*b)
	{
		if ((*b)->next == NULL)
			break ;
		*b = (*b)->next;
	}
	(*b)->next = sauvegarde;
	sauvegarde->next->prev = NULL;
	sauvegarde->prev = *b;
	sauvegarde->next = NULL;
	*b = return_adress;
}

void	pseudo_rra(t_pile **a)
{
	t_pile	*sauvegarde;
	t_pile	*avant_dernier;

	sauvegarde = *a;
	while (*a)
	{
		if ((*a)->next == NULL)
			break ;
		*a = (*a)->next;
	}
	avant_dernier = (*a)->prev;
	(*a)->prev = NULL;
	if (*a != sauvegarde)
	{
		(*a)->next = sauvegarde;
		sauvegarde->prev = *a;
		if (avant_dernier)
			avant_dernier->next = NULL;
	}
	else
	{
		(*a)->next = NULL;
		(*a)->prev = NULL;
	}
}

void	pseudo_rrb(t_pile **b)
{
	t_pile *sauvegarde;
	t_pile *avant_dernier;

	sauvegarde = *b;
	while (*b)
	{
		if ((*b)->next == NULL)
			break ;
		*b = (*b)->next;
	}
	avant_dernier = (*b)->prev;
	(*b)->prev = NULL;
	if (*b != sauvegarde)
	{
		(*b)->next = sauvegarde;
		sauvegarde->prev = *b;
		if (avant_dernier)
			avant_dernier->next = NULL;
	}
	else
	{
		(*b)->next = NULL;
		(*b)->prev = NULL;
	}
}