/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:12:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 15:13:50 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	recurse_nbr(long nbr, char *base)
{
	int	printed;

	printed = 0;
	if (nbr < ft_strlen(base))
		printed += ft_putchar(base[nbr % ft_strlen(base)]);
	else if (nbr >= ft_strlen(base))
	{
		printed += recurse_nbr(nbr / ft_strlen(base), base);
		printed += ft_putchar(base[nbr % ft_strlen(base)]);
	}
	return (printed);
}

int	ft_putnbr_base(int nbr, char *base)
{
	int		printed;
	long	n;

	printed = 0;
	n = nbr;
	if (nbr < 0)
	{
		printed += ft_putchar('-');
		n *= -1;
	}
	printed += recurse_nbr(n, base);
	return (printed);
}
