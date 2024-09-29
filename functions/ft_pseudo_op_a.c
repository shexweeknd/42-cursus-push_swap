/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pseudo_op_a.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:37:59 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/15 13:13:11 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pseudo_sa(t_pile **a)
{
	t_pile	*premier;
	t_pile	*second;
	t_pile	*troisieme;

	if (!a || !(*a)->next)
		return ;
	premier = *a;
	second = (*a)->next;
	troisieme = (*a)->next->next;
	second->prev = NULL;
	second->next = premier;
	premier->prev = second;
	if (troisieme)
	{
		premier->next = troisieme;
		troisieme->prev = premier;
	}
	else
		premier->next = NULL;
	*a = second;
}

void	pseudo_pa(t_pile **a, t_pile **b)
{
	t_pile	*first_elem_a;
	t_pile	*first_elem_b;
	t_pile	*second_elem_b;

	first_elem_a = *a;
	first_elem_b = *b;
	if (!*b)
		return ;
	if ((*b)->next)
		second_elem_b = (*b)->next;
	else
		second_elem_b = NULL;
	first_elem_a->prev = first_elem_b;
	first_elem_b->next = first_elem_a;
	if (second_elem_b)
		second_elem_b->prev = NULL;
	*a = first_elem_b;
	*b = second_elem_b;
}

void	pseudo_ra(t_pile **a)
{
	t_pile	*sauvegarde;
	t_pile	*return_adress;

	sauvegarde = *a;
	if (!*a)
		return ;
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

void	pseudo_rra(t_pile **a)
{
	t_pile	*sauvegarde;
	t_pile	*avant_dernier;

	sauvegarde = *a;
	if (!*a)
		return ;
	*a = get_last_elem(*a);
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
