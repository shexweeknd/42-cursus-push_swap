/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/15 13:12:33 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sb(t_pile **b)
{
	t_pile	*premier;
	t_pile	*second;
	t_pile	*troisieme;

	if (!b || !(*b)->next)
		return ;
	premier = *b;
	second = (*b)->next;
	troisieme = (*b)->next->next;
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
	*b = second;
	write(1, "sb\n", 3);
}

void	create_first(t_pile **a, t_pile **b)
{
	t_pile	*first_elem_a;
	t_pile	*second_elem_a;

	first_elem_a = *a;
	second_elem_a = NULL;
	if ((*a)->next)
		second_elem_a = (*a)->next;
	*b = first_elem_a;
	(*b)->next = NULL;
	if (second_elem_a)
		second_elem_a->prev = NULL;
	*a = second_elem_a;
}

void	pb(t_pile **b, t_pile **a)
{
	t_pile	*first_elem_b;
	t_pile	*first_elem_a;
	t_pile	*second_elem_a;

	if (!*b)
	{
		create_first(a, b);
		write(1, "pb\n", 3);
		return ;
	}
	first_elem_b = *b;
	first_elem_a = *a;
	if (!*a)
		return ;
	if ((*a)->next)
		second_elem_a = (*a)->next;
	else
		second_elem_a = NULL;
	first_elem_b->prev = first_elem_a;
	first_elem_a->next = first_elem_b;
	if (second_elem_a)
		second_elem_a->prev = NULL;
	*b = first_elem_a;
	*a = second_elem_a;
	write(1, "pb\n", 3);
}

void	rb(t_pile **b)
{
	t_pile	*sauvegarde;
	t_pile	*return_adress;

	if (!*b)
		return ;
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
	write(1, "rb\n", 3);
}

void	rrb(t_pile **b)
{
	t_pile	*sauvegarde;
	t_pile	*avant_dernier;

	if (!*b)
		return ;
	sauvegarde = *b;
	*b = get_last_elem(*b);
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
	write(1, "rrb\n", 4);
}
