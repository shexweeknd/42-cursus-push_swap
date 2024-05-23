/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/23 07:33:29 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	verify_argv(int argc, char **argv)
{
	// voir si un element de argv est !ft_isdigit alors return 1
	// creer un array de taille argc pour contenir les atoi
	// faire un ft_atoi de chaque composant de argv puis remplir dans le array
	// verifier les repetitions dans l'array puis return 1 si erreur
	return (0);
}

int	main(int argc, char **argv)
{
	if (!(argc >= 2) || !verify_argv(argv))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// split des argv
	return (0);
}
