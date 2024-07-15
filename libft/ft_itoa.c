/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 09:17:54 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:14:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_get_size(unsigned long nbr)
{
	size_t	res;

	res = 1;
	while (nbr >= 10)
	{
		nbr /= 10;
		res++;
	}
	return (res);
}

static long	ft_absolute(int nbr)
{
	if (nbr == -2147483648)
		return (2147483648);
	if (nbr < 0)
		nbr *= -1;
	return (nbr);
}

static char	*ft_malloc(size_t size, int sign)
{
	char	*buffer;

	if (sign)
		buffer = (char *)malloc(sizeof(char) * (size + 2));
	else
		buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	return (buffer);
}

static void	ft_fill_buffer(char *buffer, size_t size, unsigned long nbr)
{
	buffer[size] = '\0';
	while (size)
	{
		buffer[--size] = nbr % 10 + 48;
		nbr /= 10;
	}
	return ;
}

char	*ft_itoa(int n)
{
	char	*buffer;
	size_t	size;
	int		sign;
	long	tmp;

	sign = 0;
	if (n < 0)
		sign = 1;
	tmp = ft_absolute(n);
	size = ft_get_size((long)tmp);
	buffer = ft_malloc(size, sign);
	if (!buffer)
		return (NULL);
	if (sign)
	{
		buffer[0] = '-';
		ft_fill_buffer(buffer + 1, size, (unsigned long)tmp);
	}
	else
		ft_fill_buffer(buffer, size, (unsigned long)tmp);
	return (buffer);
}
