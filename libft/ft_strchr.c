/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 15:03:18 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:16:45 by hramaros         ###   ########.fr       */
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
	return (0);
}
