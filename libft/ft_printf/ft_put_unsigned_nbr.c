/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_unsigned_nbr.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:00:27 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 15:47:44 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_unsigned_nbr(unsigned int nb)
{
	unsigned int	n;
	int				printed;

	n = nb;
	printed = 0;
	if (n >= 10)
	{
		printed += ft_putnbr_base(n / 10, "0123456789");
		n %= 10;
	}
	printed += ft_putchar_i(n + 48);
	return (printed);
}
