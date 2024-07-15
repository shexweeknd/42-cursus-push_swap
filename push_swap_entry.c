/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_entry.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:32 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 14:23:30 by hramaros         ###   ########.fr       */
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
char	**combine_splitted(char **s1, char **s2)
{
	char	**to_free_one;
	char	**to_free_two;
	char	**result;
	char	**temp;
	size_t	total_size;

	total_size = get_twodim_size((char **)s1) + get_twodim_size((char **)s2);
	if (!s2)
		return (ft_free_splitted(s1), NULL);
	temp = (char **)malloc(sizeof(char *) * (total_size + 1));
	if (!temp)
		return (ft_free_splitted(s1), ft_free_splitted(s2), NULL);
	result = temp;
	to_free_one = s1;
	while (s1 && *s1)
		*temp++ = *s1++;
	if (to_free_one)
		free(to_free_one);
	to_free_two = s2;
	while (s2 && *s2)
		*temp++ = *s2++;
	*temp = 0;
	free(to_free_two);
	return (result);
}

char	**set_ar(char **ar, char **argv)
{
	while (*++argv)
	{
		ar = combine_splitted(ar, ft_split_by(*argv, ' '));
		if (!ar)
			return (NULL);
	}
	return (ar);
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
	char	**ar;
	char	**to_free;
	t_pile	*fst_el;
	size_t	s;
	int		cgm;

	fst_el = init_pile(0);
	ar = NULL;
	if (!fst_el)
		return (NULL);
	ar = set_ar(ar, argv);
	if (!ar)
		return (free_elem(fst_el), NULL);
	s = ft_contentlen(ar);
	cgm = 0;
	to_free = ar;
	while (*ar)
	{
		if (!ft_isnumber(*ar))
			return (free_elem(fst_el), NULL);
		if (!ft_pileadd_back(fst_el, ft_atol(*ar++), cgm++, s))
			return (NULL);
	}
	return (ft_free_splitted(to_free), fst_el);
}
