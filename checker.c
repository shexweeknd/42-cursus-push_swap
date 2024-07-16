/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/16 10:35:46 by hramaros         ###   ########.fr       */
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
		pseudo_pa(a, b);
	else if (!ft_strncmp(operation, "pb\n", 3))
		pseudo_pb(b, a);
	else if (!ft_strncmp(operation, "sa\n", 3))
		pseudo_sa(a);
	else if (!ft_strncmp(operation, "sb\n", 3))
		pseudo_sb(b);
	else if (!ft_strncmp(operation, "ra\n", 3))
		pseudo_ra(a);
	else if (!ft_strncmp(operation, "rb\n", 3))
		pseudo_rb(b);
	else if (!ft_strncmp(operation, "rra\n", 4))
		pseudo_rra(a);
	else if (!ft_strncmp(operation, "rrb\n", 4))
		pseudo_rrb(b);
	else if (!ft_strncmp(operation, "ss\n", 3))
		pseudo_ss(a, b);
	else if (!ft_strncmp(operation, "rr\n", 3))
		pseudo_rr(a, b);
	else if (!ft_strncmp(operation, "rrr\n", 4))
		pseudo_rrr(a, b);
	else
		return (free(operation), -1);
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
	while (operation && *operation)
	{
		if (compute_op(operation, a, b) == -1)
			return (free_pile(a), free_pile(b), render_exit(), 1);
		free(operation);
		operation = get_next_line(0);
	}
	if (*a && ft_is_sorted(*a))
	{
		if ((*b != NULL))
			return (free(operation), ko(a, b));
		return (free(operation), ok(a, b));
	}
	return (free(operation), ko(a, b));
}

int	main(int argc, char **argv)
{
	t_pile	**a;
	t_pile	**b;
	int		i;

	a = (t_pile **)malloc(sizeof(t_pile *));
	if (!a)
		return (write(2, "Erreur d'allocation de la pile\n", 31), 1);
	if (!(argc >= 2) && (argc != 1))
		return (free(a), render_exit(), 1);
	if (argc == 2)
		argc = get_args_numbers(argv[1]);
	else if (argc == 1)
		return (free(a), 0);
	else
		argc -= 1;
	i = 1;
	while (argv[i])
		if (!ft_isnumber(argv[i++]))
			return (free(a), render_exit(), 1);
	*a = verify_argv(argv);
	if (ft_has_duplicates(*a) || ft_has_greater_than(*a, INT_MAX))
		return (free_pile(a), render_exit(), 0);
	if (*a == NULL)
		return (free_pile(a), 0);
	return (checker(a));
}
