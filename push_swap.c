/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/28 08:00:25 by hramaros         ###   ########.fr       */
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
	split et a prendre les arguments entant que tableau d'int
 *
 * @param argv Contient tous les arguments du main
 * @return int**
 * @date 2024-05-27
 */
int	**verify_argv(char **argv)
{
	// void	**array;
	// int		**result;

	// array = NULL;
	// if (!argv[2])
	// 	array = (void **)ft_split(argv[1], ' ');
	// else
	// 	array = (void **)argv;
	// result = (int **)malloc(sizeof(int) * ft_contentlen(array));
	// while (*array)
	// {
	// 	if (!ft_isnumber(*(char **)array))
	// 	{
	// 		free(result);
	// 		return (NULL);
	// 	}
	// 	**result = ft_atoi(*(char **)array);
	// 	result++;
	// 	array++;
	// }
	// return (result);rxit
}

int	main(int argc, char **argv)
{
	int	**array;

	array = verify_argv(argv);
	if (!(argc >= 2) || (*array == NULL))
	{
		write(1, "Error\n", 6);
		return (1);
	}
	// si on a le array alors on implemente l'algo
	ft_printf("Implementation de l'algorithme de tri\n");
	return (0);
}
