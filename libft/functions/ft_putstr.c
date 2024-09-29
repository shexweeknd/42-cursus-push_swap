/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:10:15 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 15:10:24 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr(char *str)
{
	int	printed;

	if (!str)
	{
		printed = ft_putstr("(null)");
		return (printed);
	}
	printed = 0;
	while (*str)
	{
		printed += ft_putchar(*str);
		str++;
	}
	return (printed);
}
