/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:47 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 13:46:17 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str)
{
	int	result;

	while (ft_isspace(*str))
		str++;
	if (!*str)
		return (0);
	result = 1;
	while (*str)
	{
		if (ft_isspace(*str) && !ft_isspace(*(str + 1)) && *(str + 1))
			result++;
		str++;
	}
	return (result);
}

static char	*skip_spaces(char *str)
{
	while (ft_isspace(*str))
		str++;
	return (str);
}

static int	fullfill_result(char **result, int index, char *str)
{
	int	k;

	if (!ft_isspace(*str))
	{
		result[index] = (char *)malloc(sizeof(char) * (word_len(str) + 1));
		if (!result[index])
			return (ft_free_splitted(result), 0);
		result[index][word_len(str)] = 0;
		k = 0;
		while (!ft_isspace(*str) && *str)
		{
			result[index][k] = *str;
			k++;
			str++;
		}
	}
	return (1);
}

char	**ft_split(char *str)
{
	char	**result;
	int		index;

	str = skip_spaces(str);
	if (!*str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str) + 1));
	if (!result)
		return (NULL);
	result[count_words(str)] = NULL;
	index = 0;
	while (*str)
	{
		str = skip_spaces(str);
		if (!fullfill_result(result, index, str))
			return (NULL);
		str += word_len(str);
		str = skip_spaces(str);
		index++;
	}
	return (result);
}
