/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 12:06:16 by hramaros          #+#    #+#             */
/*   Updated: 2024/03/01 09:11:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(char *str)
{
	int	printed;

	printed = 0;
	if (str == (char *)(0))
		return (write(1, "(null)", 6));
	while (*str)
		printed += write(1, str++, 1);
	return (printed);
}
