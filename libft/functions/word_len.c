/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_len.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:08:30 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 12:08:40 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_len(char *str)
{
	int	result;

	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (0);
	result = 0;
	while (*str && !ft_isspace(*str))
	{
		result++;
		str++;
	}
	return (result);
}
