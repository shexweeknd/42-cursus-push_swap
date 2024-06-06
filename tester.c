/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tester.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 11:11:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/06 13:15:06 by hramaros         ###   ########.fr       */
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
	// sa(a);
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
