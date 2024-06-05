/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/05 10:42:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"

/**
 * @brief compte la taille du tableau de donne
 *
 * @param list
 * @return size_t
 * @date 2024-05-27
 */
size_t	ft_contentlen(void **list)
{
	size_t	len;

	len = 0;
	while (*list++)
		len++;
	return (len);
}

/**

 * @brief verifie s'il n'y a pas d'erreur dans les arguments,
	split et a prendre les arguments en tant que tableau d'int
 *
 * @param argv Contient tous les arguments du main
 * @return int**
 * @date 2024-05-27
 */
int	*verify_argv(char **argv)
{
	void	**array;
	size_t	array_size;
	int		*result;

	array = NULL;
	if (!argv[2])
		array = (void **)ft_split(argv[1], ' ');
	else
		array = (void **)(argv + 1);
	array_size = ft_contentlen(array);
	result = (int *)malloc(sizeof(int) * array_size);
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
			return (free(result), NULL);
		*result = ft_atoi(*(char **)array);
		result++;
		array++;
	}
	return ((result - array_size));
}

/**
 * @brief fonction d'initialisation de la pile
 *
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*init_pile(void)
{
	t_pile	*first_elem;

	first_elem = malloc(sizeof(t_pile *));
	first_elem->next = NULL;
	first_elem->prev = NULL;
	return (first_elem);
}

/**
 * @brief insert la liste d'array de int dans la pile
 *
 * @param array
 * @return t_pile*
 * @date 2024-06-05
 */
t_pile	*set_pile(int *array)
{
	t_pile	*first_elem;
	t_pile	*pile_elem;

	first_elem = init_pile();
	pile_elem = first_elem;
	while (*array)
	{
		pile_elem->value = *array;
		pile_elem->next = init_pile();
		pile_elem = pile_elem->next;
	}
	return (first_elem);
}

int	main(int argc, char **argv)
{
	int		*array;
	t_pile	*list;

	array = verify_argv(argv);
	list = set_pile(array);
	if (!(argc >= 2) || (array == NULL))
		return (write(1, "Error\n", 6), 1);
	// si on a le array alors on implemente l'algo
	ft_printf("Implementation de l'algorithme de tri\n");
	return (0);
}
