/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 07:38:14 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/24 07:44:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft.h"
#include "push_swap.h"
#include "utils.h"

size_t	ft_contentlen(void **list)
{
	size_t	len;

	len = 0;
	while (*list++)
		len++;
	return (len);
}

int	**verify_argv(char **argv)
{
	void	**array;
	int		**result;

	array = NULL;
	if (!argv[2])
		array = (void **)ft_split(argv[1], ' ');
	else
		array = (void **)argv;
	result = (int **)malloc(sizeof(int) * ft_contentlen(array));
	while (*array)
	{
		if (!ft_isnumber(*(char **)array))
		{
			free(result);
			return (NULL);
		}
		**result = ft_atoi(*(char **)array);
		result++;
		array++;
	}
	return (result);
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
