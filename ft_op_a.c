/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:37:59 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/10 11:48:20 by hramaros         ###   ########.fr       */
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
void	sa(t_pile **a)
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
	write(1, "sa\n", 3);
}

/**
 * @brief Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
void	pa(t_pile **a, t_pile **b)
{
	t_pile	*first_elem_a;
	t_pile	*first_elem_b;
	t_pile	*second_elem_b;

	first_elem_a = *a;
	first_elem_b = *b;
	if (!*b)
		return ;
	if ((*b)->next)
	{
		second_elem_b = (*b)->next;
	}
	else
	{
		second_elem_b = NULL;
	}
	first_elem_a->prev = first_elem_b;
	first_elem_b->next = first_elem_a;
	if (second_elem_b)
		second_elem_b->prev = NULL;
	*a = first_elem_b;
	if (second_elem_b)
		*b = second_elem_b;
	write(1, "pa\n", 3);
}

/**
 * @brief Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
void	ra(t_pile **a)
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
	write(1, "ra\n", 3);
}

/**
 * @brief Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
void	rra(t_pile **a)
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
	write(1, "rra\n", 3);
}
