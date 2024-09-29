/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42Antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:18 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 14:29:59 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	if ((char)c == '\0')
	{
		while (*str++)
			;
		return ((char *)(--str));
	}
	while (*str)
		if (*str++ == (char)c)
			return ((char *)(--str));
	return (NULL);
}
