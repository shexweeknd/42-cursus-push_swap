/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_no_nl.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 10:19:20 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/18 10:33:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen_no_nl(const char *s)
{
	int	count;

	if (!s || *s == '\n')
		return (0);
	count = 0;
	while (s[count] && s[count] != '\n')
		count++;
	return (count);
}
