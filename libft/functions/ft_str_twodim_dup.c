/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_twodim_dup.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/22 11:02:51 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/22 11:08:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_str_twodim_dup(char **src)
{
	char	**result;
	int		index;

	result = (char **)malloc(sizeof(char *) * (get_twodim_size(src) + 1));
	if (!result)
		return (NULL);
	result[get_twodim_size(src)] = NULL;
	index = 0;
	while (*src)
	{
		result[index] = ft_strdup(*src);
		if (!result[index])
			return (ft_free_splitted(result), NULL);
		src++;
		index++;
	}
	return (result);
}
