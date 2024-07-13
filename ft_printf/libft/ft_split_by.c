/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_by.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/13 12:13:44 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/13 13:24:32 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char *str, char sep)
{
	int	result;

	while (*str == sep)
		str++;
	if (!*str)
		return (0);
	result = 1;
	while (*str)
	{
		if ((*str == sep) && (*(str + 1) != sep) && *(str + 1))
			result++;
		str++;
	}
	return (result);
}

static void	ft_free(char **result)
{
	int	index;

	index = 0;
	while (result[index])
	{
		free(result[index]);
		index++;
	}
	free(result);
}

static char	*skip_sep(char *str, char sep)
{
	while (*str == sep)
		str++;
	return (str);
}

static int	fullfill_result(char **result, int index, char *str, char sep)
{
	int	k;

	if (*str != sep)
	{
		result[index] = (char *)malloc(sizeof(char) * (word_len_sep(str, sep)
					+ 1));
		if (!result[index])
			return (ft_free(result), 0);
		result[index][word_len_sep(str, sep)] = 0;
		k = 0;
		while ((*str != sep) && *str)
		{
			result[index][k] = *str;
			k++;
			str++;
		}
	}
	return (1);
}

char	**ft_split_by(char *str, char sep)
{
	char **result;
	int index;

	str = skip_sep(str, sep);
	if (!*str)
		return (NULL);
	result = (char **)malloc(sizeof(char *) * (count_words(str, sep) + 1));
	if (!result)
		return (NULL);
	result[count_words(str, sep)] = NULL;
	index = 0;
	while (*str)
	{
		str = skip_sep(str, sep);
		if (!fullfill_result(result, index, str, sep))
			return (NULL);
		while (*str && (*str != sep))
			str++;
		str = skip_sep(str, sep);
		index++;
	}
	return (result);
}