/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:38:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/05 09:32:59 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief verifie si la chaine est seulement constitue de chiffres
 *
 * @param str
 * @return int
 * @date 2024-05-27
 */
int	ft_isnumber(const char *str)
{
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str)
		if (!ft_isdigit(*str++))
			return (0);
	return (2048);
}