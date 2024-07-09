/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/09 15:01:47 by hramaros         ###   ########.fr       */
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

int	get_numbers_of_family(t_pile **a)
{
	int	result;

	if (get_pile_size(*a) < 100)
		result = 3;
	else if (get_pile_size(*a) < 600)
		result = 6;
	else if (get_pile_size(*a) > 600)
		result = 7;
	return (result);
}

long	*fullfill_array(t_pile *pile, int array_size)
{
	long	*result;
	t_pile	*first_elem;
	int		i;

	first_elem = pile;
	result = malloc(sizeof(long) * array_size);
	if (!result)
		return (NULL);
	ft_bezero(result, array_size);
	*result = *get_min_value_in(pile)->value;
	i = 1;
	while (pile)
	{
		if (*pile->value > *get_min_value_in(first_elem)->value)
		{
			result[i] = *pile->value;
			i++;
		}
		pile = pile->next;
	}
	sort_long_tab(result, array_size);
	return (result);
}

int	get_greaters(t_pile *pile, long to_compare)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (*pile->value > to_compare)
			result++;
		pile = pile->next;
	}
	return (result + 1);
}

/**
	assigne a tous les elements de pile,
		les deux premieres identifiants de famille
 */
int	set_family(t_pile *pile, int first_family_id, int max_members)
{
	int		fst_fam;
	int		sec_fam;
	t_pile	*first_elem;
	long	*array_of_greater;
	int		i;

	first_elem = pile;
	get_min_value_in(pile)->family = first_family_id;
	fst_fam = 1;
	sec_fam = 0;
	array_of_greater = fullfill_array(pile, get_greaters(pile,
				*get_min_value_in(pile)->value));
	i = 0;
	while (pile && !(fst_fam == max_members && sec_fam == max_members))
	{
		if (*pile->value == array_of_greater[i])
		{
			if (fst_fam < (max_members + 1))
			{
				pile->family = first_family_id;
				fst_fam++;
			}
			else
			{
				pile->family = first_family_id + 1;
				sec_fam++;
			}
			pile = first_elem;
			i++;
			continue ;
		}
		pile = pile->next;
	}
	return (free(array_of_greater), 0);
}

/**
	push vers b dans le bon ordre les familles concernees
 */
void	push_family_to_b(int first_family_id, t_pile **a, t_pile **b)
{
	int	second_family_id;

	while (get_pile_size(*a) > 3)
	{
		if ((*a)->family > 0 && ((*a)->family % 2 == 0))
		{
			pb(a, b);
		}
		else
		{
			pb(a, b);
			rb(b);
		}
		ra(a);
	}
}

void	put_in_b(t_pile **a, t_pile **b)
{
	int	chunk_size;
	int	n;
	int	last_family_id;

	n = get_numbers_of_family(a);
	chunk_size = get_pile_size(*a) / n;
	last_family_id = 1;
	while (get_pile_size(*a) > 3)
	{
		set_family(*a, last_family_id, chunk_size);
		print_families(a);
		push_family_to_b(last_family_id, a, b);
		last_family_id += 2;
	}
}

void	put_in_a(t_pile **a, t_pile **b)
{
	while (*b != NULL)
	{
		set_b_target(a, b);
		set_index(a);
		while ((*b)->target != *a)
		{
			if ((*b)->target->index > (get_pile_size(*a) / 2))
				rra(a);
			else
				ra(a);
		}
		pa(a, b);
	}
}

void	last_round(t_pile **a, t_pile *min)
{
	while (*a != min)
	{
		set_index(a);
		if (min->index > (get_pile_size(*a) / 2))
			rra(a);
		else
			ra(a);
	}
}

void	big_sort(t_pile **a)
{
	t_pile	**b;

	b = (t_pile **)malloc(sizeof(t_pile *));
	if (!b)
		return ;
	*b = NULL;
	put_in_b(a, b);
	mini_sort(a);
	put_in_a(a, b);
	last_round(a, get_min_value_in(*a));
	// printf("\n");
	// print_pile(a);
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
		return (free_pile(a), write(2, "Error\n", 6), 1);
	if (argc == 2)
		argc = get_args_numbers(argv[1]);
	else if (argc == 1)
		return (free_pile(a), 0);
	else
		argc -= 1;
	i = 1;
	while (argv[i])
		if (!ft_isnumber(argv[i++]))
			return (free_pile(a), write(2, "Error\n", 6), 1);
	*a = verify_argv(argv);
	if (ft_has_duplicates(*a) || ft_has_greater_than(*a, INT_MAX))
		return (free_pile(a), write(2, "Error\n", 6), 0);
	if (ft_is_sorted(*a) || (*a == NULL))
		return (free_pile(a), 0);
	return (push_swap(a), 0);
}
