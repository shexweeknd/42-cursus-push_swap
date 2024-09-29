/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:25:34 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:25:46 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * @brief renvoie la taille du tableau a deux dimensions
 *
 * @param splitted
 * @return size_t
 * @date 2024-06-10
 */
size_t	get_twodim_size(char **splitted)
{
	size_t	result;

	result = 0;
	if (!splitted)
		return (result);
	while (*splitted++)
		result++;
	return (result);
}
