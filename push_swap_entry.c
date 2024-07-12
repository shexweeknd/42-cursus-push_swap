/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:32 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 16:49:11 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/**
	* @brief combiner deux resultats de ft_split en un seul
	tableau de char a 2 dimensions
 *
 * @param s1
 * @param s2
 * @return char**
 * @date 2024-06-10
 */
// TODO verifier les conditions de leaks dans cette fonction
char	**combine_splitted(char **s1, char **s2)
{
	char	**result;
	char	**temp;
	size_t	total_size;

	total_size = get_twodim_size((char **)s1) + get_twodim_size((char **)s2);
	temp = (char **)malloc(sizeof(char *) * (total_size + 1));
	result = temp;
	if (!temp)
		return (free(s1), free(s2), NULL);
	while (s1 && *s1)
		*temp++ = *s1++;
	while (s2 && *s2)
		*temp++ = *s2++;
	*temp = 0;
	return (result);
}

/**
 * @brief verifie s'il n'y a pas de plus que la valeur de to_compare
 *
 * @param pile
 * @param to_compare
 * @date 2024-06-10
 */
int	ft_has_greater_than(t_pile *pile, long long to_compare)
{
	while (pile)
	{
		if (*pile->value > to_compare)
			return (1);
		pile = pile->next;
	}
	return (0);
}

/**
 * @brief verifie s'il n'y a pas de doublons dans la liste
 *
 * @param pile
 * @return int
 * @date 2024-06-10
 */
int	ft_has_duplicates(t_pile *pile)
{
	t_pile	*temp;
	t_pile	*greater_min;

	temp = pile;
	while (temp)
	{
		greater_min = temp->next;
		while (greater_min)
		{
			if (*temp->value == *greater_min->value)
				return (1);
			greater_min = greater_min->next;
		}
		temp = temp->next;
	}
	return (0);
}

/**
 * @brief verifier si la liste n'est pas deja trie des le debut
 *
 * @param pile
 * @return int
 * @date 2024-06-09
 */
int	ft_is_sorted(t_pile *pile)
{
	int	temp;

	temp = *pile->value;
	pile = pile->next;
	while (pile)
	{
		if (*pile->value < temp)
			return (0);
		temp = *pile->value;
		pile = pile->next;
	}
	return (1);
}

/**
 * @brief verifie s'il n'y a pas d'erreur dans les arguments,
	split et a prendre les arguments en tant que tableau d'int
 *
 * @param argv Contient tous les arguments du main
 * @return int**
 * @date 2024-05-27
 */
t_pile	*verify_argv(char **argv)
{
	void	**array;
	t_pile	*first_elem;
	size_t	array_size;
	int		current_greater_min;

	first_elem = init_pile(0);
	array = NULL;
	if (!first_elem)
		return (NULL);
	while (*++argv)
		array = (void **)combine_splitted((char **)array, ft_split(*argv, ' '));
	array_size = ft_contentlen(array);
	current_greater_min = 0;
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
			return (free_pile(&first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atol(*(char **)array),
				current_greater_min++, array_size))
			return (NULL);
		array++;
	}
	return (first_elem);
}
