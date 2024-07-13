/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:11:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 14:19:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

/**
 * @brief fonction main pour verifier sa
 *
 * @param argc
 * @param argv
 * @date 2024-06-06
 */
void	sa(int argc, char **argv)
{
	t_pile	**a;

	a = malloc(sizeof(t_pile **));
	if (!a)
		return (write(1, "Erreur d'allocation de la pile\n", 31), 1);
	*a = verify_argv(argv);
	if (!(argc >= 2) || (*a == NULL))
		return (write(1, "Error\n", 6), 1);
	ft_printf("Pile a: \n");
	print_pile(a);
	ft_printf("\nFinal value of pile a: \n");
	print_pile(a);
	free_pile(a);
	return (0);
}

/**
 * @brief fonction main pour verifier pa
 *
 * @param argc
 * @param argv
 * @date 2024-06-06
 */
void	pa(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;

	a = malloc(sizeof(t_pile **));
	b = malloc(sizeof(t_pile **));
	if (!a || !b)
		return (1);
	*a = verify_argv(argv);
	if (!(argc >= 2) || (*a == NULL))
		return (write(1, "Error\n", 6), 1);
	ft_printf("Pile a: \n");
	print_pile(a);
	ft_printf("\nCreated random pile: \n");
	*b = create_random_pile(4);
	print_pile(b);
	pa(a, b);
	ft_printf("\nFinal value of pile a: \n");
	print_pile(a);
	free_pile(a);
	free_pile(b);
	return (0);
}

// to ask to chatgpt

char	**combine_splitted(char **s1, char **s2)
{
	char	**to_free_one;
	char	**to_free_two;
	char	**result;
	char	**temp;
	size_t	total_size;

	total_size = get_twodim_size((char **)s1) + get_twodim_size((char **)s2);
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
	char	**array;
	char	**to_free;
	t_pile	*first_elem;
	size_t	array_size;
	int		current_greater_min;

	first_elem = init_pile(0);
	array = NULL;
	if (!first_elem)
		return (NULL);
	while (*++argv)
		array = combine_splitted(array, ft_split_by(*argv, ' '));
	array_size = ft_contentlen(array);
	current_greater_min = 0;
	to_free = array;
	while (*array)
	{
		if (!ft_isnumber(*array))
			return (free_pile(&first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atol(*array), current_greater_min++,
				array_size))
			return (NULL);
		array++;
	}
	return (ft_free_splitted(to_free), first_elem);
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
