/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/09 12:37:59 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
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
		ft_printf("%d\n", (*pile)->value);
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
int	ft_pileadd_back(t_pile *elem, int number, int remaining_args, int all_args)
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
	if (!argv[2])
		array = (void **)ft_split(argv[1], ' ');
	else
		array = (void **)(argv + 1);
	array_size = ft_contentlen(array);
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
			return (free_pile(&first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atoi(*(char **)array),
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
 * @brief TODO verifier si la liste n'est pas deja trie des le debut
 * 
 * @param pile 
 * @return int 
 * @date 2024-06-09
 */
int ft_is_sorted(t_pile *pile)
{
	int result;

	result = 0;
	while ()
	return (result);
}

int	main(int argc, char **argv)
{
	t_pile	**a;

	a = malloc(sizeof(t_pile **));
	if (!a)
		return (write(1, "Erreur d'allocation de la pile\n", 31), 1);
	if (!(argc >= 2))
		return (write(1, "Error\n", 6), 1);
	if (argc == 2)
		argc = get_args_numbers(argv[1]);
	else
		argc -= 1;
	*a = verify_argv(argv, argc);
	ft_printf("Pile a: \n");
	print_pile(a);
	rra(a);
	ft_printf("\nFinal value of pile a: \n");
	print_pile(a);
	free_pile(a);
	return (0);
}
