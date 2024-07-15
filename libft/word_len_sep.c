/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   word_len_sep.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 13:11:43 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 13:12:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	word_len_sep(char *str, char sep)
{
	int	result;

	while (*str == sep)
		str++;
	if (!*str)
		return (0);
	result = 0;
	while (*str && (*str != sep))
	{
		result++;
		str++;
	}
	return (result);
}
