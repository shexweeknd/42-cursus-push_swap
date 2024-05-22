/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 16:18:07 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:15:14 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	size_t	total;
	size_t	i;
	size_t	j;

	total = ft_strlen(s1) + ft_strlen(s2);
	ret = malloc(sizeof(char) * total + 1);
	if (!ret)
		return (NULL);
	i = 0;
	if (s1[0])
	{
		j = 0;
		while (s1[j])
			ret[i++] = s1[j++];
	}
	if (s2[0])
	{
		j = 0;
		while (s2[j])
			ret[i++] = s2[j++];
	}
	ret[total] = '\0';
	return (ret);
}
