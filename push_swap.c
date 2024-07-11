/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/11 14:23:49 by hramaros         ###   ########.fr       */
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

	if (get_pile_size(*a) <= 100)
		result = 3;
	else
		result = 6;
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

void	set_family_id(long value, t_pile *pile, int family_id)
{
	while (pile)
	{
		if (*pile->value == value)
			pile->family = family_id;
		pile = pile->next;
	}
}
/**
	assigne a tous les elements de pile,
		les deux premieres identifiants de famille
	*/
void	set_family(t_pile *pile, int first_family_id, int max_members)
{
	long	greater_min;
	long	last_min;
	int		members;
	t_pile	*first_elem;

	first_elem = pile;
	while (*pile->value == *get_min_value_in(pile)->value)
		pile = pile->next;
	last_min = *get_min_value_in(first_elem)->value;
	greater_min = *get_max_value_in(first_elem)->value;
	get_min_value_in(first_elem)->family = first_family_id;
	members = 1;
	while (members < (max_members * 2))
	{
		if ((*pile->value > last_min) && (*pile->value < greater_min))
			greater_min = *pile->value;
		pile = pile->next;
		if (!pile)
		{
			if (members < max_members)
				set_family_id(greater_min, first_elem, first_family_id);
			else if (members < (max_members * 2))
				set_family_id(greater_min, first_elem, first_family_id + 1);
			members++;
			last_min = greater_min;
			pile = first_elem;
			greater_min = *get_max_value_in(first_elem)->value;
		}
	}
}

int	is_family_set(t_pile *pile)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family != 0)
			result = 1;
		pile = pile->next;
	}
	return (result);
}

int	is_any_fammemb(t_pile *pile, int id)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family == id)
			result = 1;
		pile = pile->next;
	}
	return (result);
}

/**
	push vers b dans le bon ordre les familles concernees
 */
void	push_family_to_b(int first_family_id, t_pile **a, t_pile **b)
{
	while (get_pile_size(*a) > 3 && is_family_set(*a))
	{
		if (get_pile_size(*a) == 4)
			pb(b, a);
		else if ((*a)->family == 0)
			ra(a);
		else if (((*a)->family > 0 && ((*a)->family % 2 == 0)) || !*b)
			pb(b, a);
		else if ((*a)->family > 0 && ((*a)->family % 2 == 1))
		{
			pb(b, a);
			if ((*a)->family == 0)
				rr(a, b);
			else
				rb(b);
		}
	}
}

void	put_in_b(t_pile **a, t_pile **b)
{
	int	chunk_size;
	int	last_family_id;

	last_family_id = 1;
	while (get_pile_size(*a) > 3)
	{
		chunk_size = get_pile_size(*a) / get_numbers_of_family(a);
		set_family(*a, last_family_id, chunk_size);
		// print_families(a);
		push_family_to_b(last_family_id, a, b);
		last_family_id += 2;
	}
}

int	get_max_family_id(t_pile *pile)
{
	int	result;

	result = 0;
	while (pile)
	{
		if (pile->family > result)
			result = pile->family;
		pile = pile->next;
	}
	return (result);
}

void	send_back_to_a(t_pile **a, t_pile **b)
{
	int	family_to_push;

	family_to_push = get_max_family_id(*b);
	while (*b != NULL)
	{
		if (!is_any_fammemb(*b, family_to_push))
			family_to_push--;
		set_b_target(a, b);
		set_index(a);
		if ((*b)->family != family_to_push)
			rrb(b);
		while ((*b)->target != *a)
		{
			set_index(a);
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

void	fix_first_members(t_pile *pile)
{
	int		fam_id;
	t_pile	*last_member;
	t_pile	*first_elem;

	first_elem = pile;
	fam_id = 0;
	while (pile)
	{
		if (pile->family != 0)
		{
			fam_id = pile->family;
			last_member = pile;
			break ;
		}
		pile = pile->next;
	}
	while (first_elem != last_member)
	{
		first_elem->family = fam_id;
		first_elem = first_elem->next;
	}
}

void	fix_last_members(t_pile *pile)
{
	int		fam_id;
	t_pile	*last_member;
	t_pile	*last_elem;
	t_pile	*curr;

	last_elem = get_last_elem(pile);
	curr = last_elem;
	while (curr)
	{
		if (curr->family != 0)
		{
			fam_id = curr->family;
			last_member = curr;
			break ;
		}
		curr = curr->prev;
	}
	while (last_elem != last_member)
	{
		last_elem->family = fam_id;
		last_elem = last_elem->prev;
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
	fix_first_members(*b);
	fix_last_members(*b);
	mini_sort(a);
	send_back_to_a(a, b);
	last_round(a, get_min_value_in(*a));
	// printf("Last families:\n");
	// print_families(a);
	// printf("Last result:\n");
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
