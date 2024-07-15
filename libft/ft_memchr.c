/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/20 18:06:10 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:14:35 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t b_size)
{
	char	*ret;

	ret = 0;
	while (b_size--)
	{
		if (*(unsigned char *)str == (unsigned char)c)
		{
			ret = (char *)str++;
			break ;
		}
		else
			str++;
	}
	return (ret);
}
