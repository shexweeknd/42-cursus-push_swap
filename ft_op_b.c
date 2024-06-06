/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_b.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:39:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/06 09:42:51 by hramaros         ###   ########.fr       */
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
t_pile	*sb(t_pile *first_elem)
{
	t_pile	*temp;
	t_pile	*premier;
	t_pile	*second;
	t_pile	*troisieme;

	if (!first_elem || !first_elem->next)
		return (first_elem);
	premier = first_elem;
	second = first_elem->next;
	troisieme = first_elem->next->next;
	second->prev = NULL;
	second->next = premier;
	premier->prev = second;
	if (troisieme)
	{
		premier->next = troisieme;
		troisieme->prev = premier;
	}
	else
	{
		premier->next = NULL;
	}
	return (second);
}

/**
 * @brief Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*pb(t_pile *first_elem)
{
	t_pile	*result;

	return (result);
}

/**
 * @brief Décale d’une position vers le haut tous les élements de la pile a.
Le premier élément devient le dernier.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*rb(t_pile *first_elem)
{
	t_pile	*result;

	return (result);
}

/**
 * @brief Décale d’une position vers le bas tous les élements de
la pile b. Le dernier élément devient le premier.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*rrb(t_pile *first_elem)
{
	t_pile *result;

	return (result);
}