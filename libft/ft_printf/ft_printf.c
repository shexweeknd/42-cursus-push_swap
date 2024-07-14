/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 09:22:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 18:00:10 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static size_t	ft_isset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static int	ft_putformat(const char *str, va_list ap)
{
	int		printed;
	char	*set;

	set = "cspdiuxX%";
	if (!ft_isset(*str, set))
		return (0);
	printed = 0;
	if (*str == 'c')
		printed += ft_putchar_i(va_arg(ap, int));
	else if (*str == 's')
		printed += ft_putstr(va_arg(ap, char *));
	else if (*str == 'p')
		printed += ft_put_addr(va_arg(ap, void *));
	else if (*str == 'd' || *str == 'i')
		printed += ft_putnbr_base(va_arg(ap, int), "0123456789");
	else if (*str == 'u')
		printed += ft_put_unsigned_nbr(va_arg(ap, unsigned int));
	else if (*str == 'x')
		printed += ft_putx(va_arg(ap, int), "0123456789abcdef");
	else if (*str == 'X')
		printed += ft_putx(va_arg(ap, int), "0123456789ABCDEF");
	else if (*str == '%')
		printed += write(1, "%", 1);
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
			printed += write(1, str, 1);
		str++;
	}
	va_end(ap);
	return (printed);
}
