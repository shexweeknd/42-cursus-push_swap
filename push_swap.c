/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/01 16:47:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_contentlen(void **list)
{
	size_t	len;

	len = 0;
	while (*list++)
		len++;
	return (len);
}

void	print_pile(t_pile **pile)
{
	t_pile	*first_elem;

	first_elem = *pile;
	while ((*pile))
	{
		printf("%ld\n", *(*pile)->value);
		*pile = (*pile)->next;
	}
	*pile = first_elem;
	return ;
}

/**
 * @brief renvoie la taille du tableau a deux dimensions
 *
 * @param splitted
 * @return size_t
 * @date 2024-06-10
 */
size_t	get_twodim_size(char **splitted)
{
	size_t	result;

	result = 0;
	if (!splitted)
		return (result);
	while (*splitted++)
		result++;
	return (result);
}

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
	int		current_cursor;

	first_elem = init_pile(0);
	array = NULL;
	if (!first_elem)
		return (NULL);
	while (*++argv)
		array = (void **)combine_splitted((char **)array, ft_split(*argv, ' '));
	array_size = ft_contentlen(array);
	current_cursor = 0;
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
			return (free_pile(&first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atol(*(char **)array),
				current_cursor++, array_size))
			return (NULL);
		array++;
	}
	return (first_elem);
}

size_t	get_args_numbers(char *argv)
{
	size_t	result;
	int		index;

	result = 0;
	index = 0;
	while (argv[index])
	{
		if (argv[index] == 32)
			index++;
		else if (ft_isnumber(&argv[index]))
		{
			result++;
			index++;
		}
		else
			return (0);
	}
	return (result);
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
 * @brief verifie s'il n'y a pas de doublons dans la liste
 *
 * @param pile
 * @return int
 * @date 2024-06-10
 */
int	ft_has_duplicates(t_pile *pile)
{
	t_pile	*temp;
	t_pile	*cursor;

	temp = pile;
	while (temp)
	{
		cursor = temp->next;
		while (cursor)
		{
			if (*temp->value == *cursor->value)
				return (1);
			cursor = cursor->next;
		}
		temp = temp->next;
	}
	return (0);
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
 * @brief trie la liste de 3 elements
 *
 * @param a
 * @date 2024-06-11
 */
void	mini_sort(t_pile **a)
{
	long	premier;
	long	deuxieme;
	long	troisieme;

	while (!ft_is_sorted(*a))
	{
		premier = *(*a)->value;
		deuxieme = *(*a)->next->value;
		troisieme = *(*a)->next->next->value;
		if ((troisieme > premier) && (troisieme > deuxieme))
			sa(a);
		else if ((premier > deuxieme) && (premier > troisieme))
			ra(a);
		else if ((deuxieme > premier) && (deuxieme > troisieme))
			rra(a);
	}
}

/**
 * @brief
 * 	1 - push les deux premiers elements
 * 	2 - set_target:
	target de A dans B est le plus petit
	proche de A sinon Le plus grand et
	directement push dans B

	3 - get_cost de effectuer les operations en fonction du cout

	4 - faire un minisort de A

	5 - set_target inverse puis push dans A

	6 - reverse rotate jusqu'a ce que le plus
		petit de A soit au top de A
 *
 * @param a
 * @date 2024-06-12
 */
void	big_sort(t_pile **a)
{
	int		index;
	t_pile	**b;
	t_pile	*min;
	t_pile	*cheapest;

	b = (t_pile **)malloc(sizeof(t_pile *));
	if (!b)
		return ;
	*b = init_pile(*(*a)->value);
	ft_pile_delfirst(a);
	index = 1;
	while ((get_pile_size(*a) > 3) && index--)
		pb(b, a);
	set_a_target(a, b);
	// TODO calcul de couts puis push dans b tant que get_pile_size(*a) > 3
	while (get_pile_size(*a) > 3)
	{
		set_costs(*a, *b);
		cheapest = get_min_cost_in(*a);
		while (cheapest != *a)
		{
			if (cheapest->index > (get_pile_size(*a) / 2))
				ra(a);
			else
				rra(a);
		}
		set_position(b, cheapest->target);
		pb(b, a);
	}
	mini_sort(a);
	// TODO push back dans la pile a avec set_b_target
	set_b_target(a, b);
	while (*b != NULL)
	{
		// TODO reviser l'algorithme turk puis pa(a, b)
	}
	// TODO mettre le plus petit dans a au dessus en faisant rra
	min = get_min_in(*a);
	while (*a != min)
	{
		if (min->index > (get_pile_size(*a) / 2))
			rra(a);
		else
			ra(a);
	}
	free_pile(a);
	free_pile(b);
}

/**
 * @brief mini_sort si la pile a moins de 3 elements,
	big_sort si la pile a n > 3 elements
 *
 * @param a
 * @date 2024-06-10
 */
void	push_swap(t_pile **a)
{
	size_t	pile_size;

	pile_size = get_pile_size(*a);
	if (pile_size == 2)
		ra(a);
	else if (pile_size == 3)
		mini_sort(a);
	else
		big_sort(a);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;
	int		i;

	a = (t_pile **)malloc(sizeof(t_pile *));
	if (!a)
		return (write(1, "Erreur d'allocation de la pile\n", 31), 1);
	if (!(argc >= 2) && (argc != 1))
		return (write(1, "Error\n", 6), 1);
	if (argc == 2)
		argc = get_args_numbers(argv[1]);
	else
		argc -= 1;
	i = 1;
	while (argv[i])
		if (!ft_isnumber(argv[i++]))
			return (write(1, "Error\n", 6), 1);
	*a = verify_argv(argv);
	if (ft_has_duplicates(*a) || ft_has_greater_than(*a, INT_MAX))
		return (free_pile(a), write(1, "Error\n", 6), 0);
	if (ft_is_sorted(*a) || (*a == NULL))
		return (free_pile(a), 0);
	push_swap(a);
	return (0);
}
