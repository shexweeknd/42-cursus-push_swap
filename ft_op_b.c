/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/10 11:42:55 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
 * @brief Intervertit les 2 premiers éléments au sommet de la pile a.
Ne fait rien s’il n’y en a qu’un ou aucun
 *
 * @return t_pile*
 * @date 2024-06-05
 */
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
	return ;
}

/**
 * @brief Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
void	pb(t_pile **b, t_pile **a)
{
	t_pile	*first_elem_b;
	t_pile	*first_elem_a;
	t_pile	*second_elem_a;

	first_elem_b = *b;
	first_elem_a = *a;
	if (!*a)
		return ;
	if ((*a)->next)
	{
		second_elem_a = (*a)->next;
	}
	else
	{
		second_elem_a = NULL;
	}
	first_elem_b->prev = first_elem_a;
	first_elem_a->next = first_elem_b;
	if (second_elem_a)
		second_elem_a->prev = NULL;
	*b = first_elem_a;
	if (second_elem_a)
		*a = second_elem_a;
	return ;
}

/**
 * @brief Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
void	rb(t_pile **b)
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

/**
 * @brief Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
void	rrb(t_pile **b)
{
	t_pile	*sauvegarde;
	t_pile	*avant_dernier;

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
	return ;
}
