/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 10:53:43 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ko(t_pile **a, t_pile **b)
{
	write(1, "KO\n", 3);
	free_pile(a);
	free_pile(b);
	return (0);
}

int	ok(t_pile **a, t_pile **b)
{
	write(1, "OK\n", 3);
	free_pile(a);
	free_pile(b);
	return (0);
}

int	compute_op(char *operation, t_pile **a, t_pile **b)
{
	if (!ft_strncmp(operation, "pa\n", 3))
		pa(a, b);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pb(b, a);
	else if (!ft_strncmp(operation, "sa\n", 3))
		sa(a);
	else if (!ft_strncmp(operation, "sb\n", 3))
		sb(b);
	else if (!ft_strncmp(operation, "ra\n", 3))
		ra(a);
	else if (!ft_strncmp(operation, "rb\n", 3))
		rb(b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		rra(a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		rrb(b);
	else if (!ft_strncmp(operation, "rr\n", 3))
		rr(a, b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		rrr(a, b);
	else
		return (-1);
	return (1);
}

int	checker(t_pile **a)
{
	char	*operation;
	t_pile	**b;

	b = (t_pile **)malloc(sizeof(t_pile *));
	if (!b)
		return (1);
	*b = NULL;
	operation = get_next_line(0);
	while (*operation)
	{
		if (compute_op(operation, a, b) == -1)
			return (ko(a, b));
		if (ft_is_sorted(*a))
			return (ok(a, b));
		operation = get_next_line(0);
	}
	return (0);
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
	return (checker(a));
}
