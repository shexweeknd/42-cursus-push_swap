/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_splitted.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:43:06 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 13:55:27 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_free_splitted(char **result)
{
	int	index;

	if (!result)
		return ;
	index = 0;
	while (result[index])
	{
		free(result[index]);
		index++;
	}
	free(result);
}
