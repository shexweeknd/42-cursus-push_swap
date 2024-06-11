/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/11 08:51:33 by hramaros         ###   ########.fr       */
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

t_pile	*init_pile(void)
{
	t_pile	*first_elem;

	first_elem = malloc(sizeof(t_pile *));
	if (!first_elem)
		return (NULL);
	first_elem->next = NULL;
	first_elem->prev = NULL;
	return (first_elem);
}

void	print_pile(t_pile **pile)
{
	t_pile	*first_elem;

	first_elem = *pile;
	while ((*pile))
	{
		printf("%ld\n", (*pile)->value);
		*pile = (*pile)->next;
	}
	*pile = first_elem;
	return ;
}

void	free_pile(t_pile **pile)
{
	t_pile	*suivant;
	t_pile	**sauvegarde;

	sauvegarde = pile;
	while (*pile)
	{
		suivant = (*pile)->next;
		free(*pile);
		*pile = suivant;
	}
	return (free(sauvegarde));
}

/**
 * @brief TODO debug pour prendre en compte number = 0
 *
 * @param elem
 * @param number
 * @return int
 * @date 2024-06-08
 */
int	ft_pileadd_back(t_pile *elem, long number, int remaining_args, int all_args)
{
	while (elem)
	{
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	if (remaining_args && (remaining_args != all_args))
	{
		elem->next = init_pile();
		elem->next->prev = elem;
		elem->next->value = number;
	}
	else
	{
		elem->value = number;
	}
	return (1);
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
t_pile	*verify_argv(char **argv, int remaining_args)
{
	void	**array;
	t_pile	*first_elem;
	size_t	array_size;
	int		all_args;

	first_elem = init_pile();
	array = NULL;
	all_args = remaining_args;
	if (!first_elem)
		return (NULL);
	while (*++argv)
		array = (void **)combine_splitted((char **)array, ft_split(*argv, ' '));
	array_size = ft_contentlen(array);
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
			return (free_pile(&first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atol(*(char **)array),
				remaining_args--, all_args))
			return (NULL);
		array++;
	}
	return (first_elem);
}

t_pile	*create_random_pile(size_t pile_size)
{
	t_pile	*pile;
	int		total_pile_size;

	pile = init_pile();
	total_pile_size = pile_size;
	while (pile_size)
		ft_pileadd_back(pile, (getpid() * pile_size) % 100, pile_size--,
			total_pile_size);
	return (pile);
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

	temp = pile->value;
	pile = pile->next;
	while (pile)
	{
		if (pile->value < temp)
			return (0);
		temp = pile->value;
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
			if (temp->value == cursor->value)
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
		if (pile->value > to_compare)
			return (1);
		pile = pile->next;
	}
	return (0);
}

/**
 * @brief TODEBUG pour l'entree 1 0 4 "2 6 8"
 *
 * @param pile
 * @return size_t
 * @date 2024-06-10
 */
size_t	get_pile_size(t_pile *pile)
{
	size_t	result;

	result = 0;
	while (pile)
	{
		result++;
		pile = pile->next;
	}
	return (result);
}

void	mini_sort(t_pile **a)
{
	long	premier;
	long	deuxieme;
	long	troisieme;

	premier = (*a)->value;
	deuxieme = (*a)->next->value;
	troisieme = (*a)->next->next->value;
	while (!ft_is_sorted(*a))
	{
		if ((troisieme > premier) && (troisieme > deuxieme))
			sa(a);
		else if ((premier > deuxieme) && (premier > troisieme))
			ra(a);
		else if ((deuxieme > premier) && (deuxieme > troisieme))
			rra(a);
	}
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
	// ft_printf("mini sorting");
	else
		// big_sort(a);
		ft_printf("big sorting");
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	int		i;

	a = malloc(sizeof(t_pile **));
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
	*a = verify_argv(argv, argc);
	if (ft_is_sorted(*a) || (*a == NULL))
		return (free_pile(a), 0);
	if (ft_has_duplicates(*a) || ft_has_greater_than(*a, INT_MAX))
		return (free_pile(a), write(1, "Error\n", 6), 0);
	push_swap(a);
	return (free_pile(a), 0);
}
