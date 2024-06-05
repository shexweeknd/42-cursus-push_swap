/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_op_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:37:59 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/05 10:18:24 by hramaros         ###   ########.fr       */
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
t_pile	*sa(t_pile *first_elem)
{
	t_pile	*temp;
	t_pile	*premier;
	t_pile	*second;
	t_pile	*troisieme;

	if (!first_elem || !first_elem->next)
		return (first_elem);
	premier = first_elem;
	second = first_elem->next;
	second->prev = NULL;
	second->next = premier;
	premier->prev = second;
	if (first_elem->next->next)
	{
		premier->next = first_elem->next->next;
		first_elem->next->next->prev = premier;
	}
	return (first_elem->next->next);
}

/**
 * @brief Prend le premier élément au sommet de b et le met sur a.
Ne fait rien si b est vide.
 *
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*pa(t_pile *first_elem)
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
t_pile	*ra(t_pile *first_elem)
{
	t_pile	*result;

	return (result);
}

/**
 * @brief Décale d’une position vers le bas tous les élements de
la pile a. Le dernier élément devient le premier.
 *
 * @param first_elem
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*rra(t_pile *first_elem)
{
	t_pile *result;

	return (result);
}