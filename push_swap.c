/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/05 13:47:41 by hramaros         ###   ########.fr       */
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

void	free_pile(t_pile *first_elem)
{
	t_pile	*suivant;

	while (first_elem)
	{
		suivant = first_elem->next;
		free(first_elem);
		first_elem = suivant;
	}
	return ;
}

int	ft_pileadd_back(t_pile *elem, int number)
{
	while (elem)
	{
		if (elem->next == NULL)
			break ;
		elem = elem->next;
	}
	if (elem->value)
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
t_pile	*verify_argv(char **argv)
{
	void	**array;
	t_pile	*first_elem;
	size_t	array_size;

	first_elem = init_pile();
	array = NULL;
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
			return (free_pile(first_elem), NULL);
		if (!ft_pileadd_back(first_elem, ft_atoi(*(char **)array)))
			return (NULL);
		array++;
	}
	return (first_elem);
}

int	main(int argc, char **argv)
{
	t_pile	*list;

	list = verify_argv(argv);
	if (!(argc >= 2) || (list == NULL))
		return (write(1, "Error\n", 6), 1);
	ft_printf("Implementation de l'algorithme de tri\n");
	free_pile(list);
	return (0);
}
