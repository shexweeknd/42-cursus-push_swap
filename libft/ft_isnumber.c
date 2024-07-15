/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:38:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/15 13:43:01 by hramaros         ###   ########.fr       */
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
	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (0);
	while (*str)
	{
		if (((*str == '-') && ft_isdigit(*(str + 1))) || ((*str == '+')
				&& ft_isdigit(*(str + 1))))
			str++;
		if (*str == ' ')
		{
			str++;
			continue ;
		}
		else if (!ft_isdigit(*str))
			return (0);
		str++;
	}
	return (2048);
}
