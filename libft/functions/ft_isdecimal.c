/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdecimal.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/29 15:11:50 by hramaros          #+#    #+#             */
/*   Updated: 2024/09/29 15:11:58 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_decimal(char *base)
{
	while (*base)
	{
		if (*base < 48 || *base > 57)
			return (0);
		base++;
	}
	return (1);
}
