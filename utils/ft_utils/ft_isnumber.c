/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isnumber.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/24 07:38:29 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/24 07:42:49 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../utils.h"
#include "libft.h"

int	ft_isnumber(const char *str)
{
	if ((*str == '-') || (*str == '+'))
		str++;
	while (*str)
		if (!ft_isdigit(*str))
			return (0);
	return (2048);
}