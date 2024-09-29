/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:54:27 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:15:37 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *str, const char *to_find, size_t n)
{
	size_t	i;
	size_t	j;
	size_t	to_find_len;

	if (ft_strlen(to_find) == 0)
		return ((char *)str);
	to_find_len = ft_strlen(to_find);
	i = 0;
	while (i < n && str[i])
	{
		j = 0;
		while (str[i + j] && str[i + j] == to_find[j] && (i + j) < n)
			j++;
		if (j == to_find_len)
			return (&((char *)str)[i]);
		i++;
	}
	return (NULL);
}
