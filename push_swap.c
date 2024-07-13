/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 16:14:06 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	{
		ra(a);
		free_pile(a);
	}
	else if (pile_size == 3)
	{
		mini_sort(a);
		free_pile(a);
	}
	else
		big_sort(a);
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	int		i;

	a = (t_pile **)malloc(sizeof(t_pile *));
	if (!a)
		return (write(1, "Erreur d'allocation de la pile\n", 31), 1);
	if (!(argc >= 2) && (argc != 1))
		return (free(a), write(2, "Error\n", 6), 1);
	if (argc == 2)
		argc = get_args_numbers(argv[1]);
	else if (argc == 1)
		return (free(a), 0);
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
