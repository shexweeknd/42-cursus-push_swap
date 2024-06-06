/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/06 10:06:48 by hramaros         ###   ########.fr       */
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

t_pile	*create_random_pile(size_t pile_size)
{
	t_pile	*pile;

	pile = init_pile();
	while (pile_size--)
		ft_pileadd_back(pile, (getpid() * pile_size) % 10);
	return (pile);
}

int	main(int argc, char **argv)
{
	t_pile	*a;
	t_pile	*b;
	t_pile	*temp_a;
	t_pile	*temp_b;

	a = verify_argv(argv);
	if (!(argc >= 2) || (a == NULL))
		return (write(1, "Error\n", 6), 1);
	ft_printf("Pile a: \n");
	temp_a = a;
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	ft_printf("\nCreated random pile: \n");
	b = create_random_pile(4);
	temp_b = b;
	while (b)
	{
		ft_printf("%d\n", b->value);
		b = b->next;
	}
	a = pa(temp_a, temp_b);
	ft_printf("\nFinal value of pile a: \n");
	while (a)
	{
		ft_printf("%d\n", a->value);
		a = a->next;
	}
	free_pile(temp_a);
	free_pile(temp_b);
	return (0);
}
