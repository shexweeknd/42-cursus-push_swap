/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 16:16:03 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ko(t_pile **a, t_pile **b)
{
	write(1, "KO\n", 3);
	free_pile(a);
	free_pile(b);
	return (1);
}

int	ok(t_pile **a, t_pile **b)
{
	write(1, "OK\n", 3);
	free_pile(a);
	free_pile(b);
	return (1);
}

void	checker(t_pile **a)
{
	char	c;
	t_pile	**b;

	b = (t_pile **)malloc(sizeof(t_pile *));
	if (!b)
		return ;
	*b = NULL;
	while (read(1, &c, 1) > 0)
	{
		if (c == 'r')
		{
			if (read(1, &c, 1) > 0 && (c == 'a' || c == 'b' || c == 'r'))
			{
				if (c == 'a')
					ra(a);
				else if (c == 'b')
					rb(b);
				else if (c == 'r')
				{
					if (read(1, &c, 1) > 0 && (c == '\n'))
						rr(a, b);
					else if (c == 'r')
						rrr(a, b);
					else if (c == 'a')
						rra(a);
					else if (c == 'b')
						rrb(b);
					else
						exit(ko(a, b));
				}
			}
			else
				exit(ko(a, b));
		}
		else if (c == 'p')
		{
			if (read(1, &c, 1) > 0 && (c == 'a' || c == 'b'))
			{
				if (c == 'a')
					pa(a, b);
				else if (c == 'b')
					pb(b, a);
				else if (read(1, &c, 1) > 0 && (c != '\n'))
					exit(ko(a, b));
			}
			else
				exit(ko(a, b));
		}
		else if (c == 's')
		{
			if (read(1, &c, 1) > 0 && (c == 'a' || c == 'b'))
			{
				if (c == 'a')
					sa(a);
				else if (c == 'b')
					sb(b);
				else if (read(1, &c, 1) > 0 && (c != '\n'))
					exit(ko(a, b));
			}
		}
		else
			exit(ko(a, b));
	}
	if (ft_is_sorted(*a))
		exit(ok(a, b));
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
	return (checker(a), 0);
}
