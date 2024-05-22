/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 16:12:17 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:14:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_copy;

	if (!dest && !src)
		return (dest);
	dest_copy = (unsigned char *)dest;
	if (n == 0)
		return (dest);
	if (src >= dest)
		while (n--)
			*(unsigned char *)dest++ = *(unsigned char *)src++;
	else if (src < dest)
		while ((long)(--n) >= 0)
			*(unsigned char *)(dest + n) = *(unsigned char *)(src + n);
	return ((void *)dest_copy);
}
