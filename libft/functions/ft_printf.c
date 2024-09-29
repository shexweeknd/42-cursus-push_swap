/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:07:32 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 15:14:02 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isset(const char *str, char *set)
{
	int	index;

	while (*str)
	{
		index = 0;
		while (set[index])
		{
			if (*str == set[index])
				return (1);
			index++;
		}
		str++;
	}
	return (0);
}

int	ft_putx(unsigned int nbr, char *base)
{
	int		printed;
	long	n;

	printed = 0;
	n = nbr;
	printed += recurse_nbr(n, base);
	return (printed);
}

int	ft_putformat(const char *str, va_list ap)
{
	int		printed;
	char	*set;

	set = "csdx%";
	if (!ft_isset(str, set))
		return (0);
	printed = 0;
	if (*str == 'c')
		printed += ft_putchar(va_arg(ap, int));
	else if (*str == 's')
		printed += ft_putstr(va_arg(ap, char *));
	else if (*str == 'd')
		printed += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (*str == 'x')
		printed += ft_putx(va_arg(ap, int), "0123456789abcdef");
	else if (*str == 'X')
		printed += ft_putx(va_arg(ap, int), "0123456789ABCDEF");
	else if (*str == '%')
		printed += ft_putchar('%');
	return (printed);
}

int	ft_printf(const char *str, ...)
{
	va_list	ap;
	int		printed;

	va_start(ap, str);
	printed = 0;
	while (*str)
	{
		if (*str == '%')
			printed += ft_putformat(++str, ap);
		else
			printed += ft_putchar(*str);
		str++;
	}
	va_end(ap);
	return (printed);
}
