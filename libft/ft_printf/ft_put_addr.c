/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_addr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 11:35:03 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/01 09:00:59 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_put_nil(void)
{
	write(1, "(nil)", 5);
	return (5);
}

static int	ft_print_data(char *data, int printed)
{
	if (printed <= 2)
	{
		if (*data == '0' && *(data + 1) == '0')
			return (0);
		if (*(data) == '0')
			return (write(1, (data + 1), 1));
	}
	return (write(1, data, 2));
}

int	ft_put_addr(void *addr)
{
	unsigned int	i;
	char			b_data[sizeof(unsigned int *)];
	char			data[2];
	char			*hex;
	int				printed;

	hex = "0123456789abcdef";
	i = 0;
	if (!addr)
		return (ft_put_nil());
	while (i < sizeof(unsigned int *))
	{
		b_data[i] = ((char *)&addr)[i];
		i++;
	}
	printed = write(1, "0x", 2);
	while (i > 0)
	{
		data[0] = hex[((char)b_data[i - 1] >> 4) & 0xf];
		data[1] = hex[(char)b_data[i-- - 1] & 0xf];
		printed += ft_print_data(data, printed);
	}
	return (printed);
}
