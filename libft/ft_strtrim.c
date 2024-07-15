/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 18:20:25 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:15:47 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_isset(const char c, const char *set)
{
	size_t	i;

	i = 0;
	while (*(set + i))
	{
		if (*(set + i) == c)
			return (1);
		i++;
	}
	return (0);
}

static size_t	ft_getstart(const char *str, const char *set)
{
	size_t	str_size;
	size_t	start_index;

	str_size = ft_strlen(str);
	start_index = 0;
	while (ft_isset(*(str + start_index), set))
		start_index++;
	if (start_index == str_size)
		return (0);
	return (start_index);
}

static size_t	ft_getend(const char *str, const char *set)
{
	size_t	str_size;

	str_size = ft_strlen(str);
	while (str_size)
		if (!ft_isset(str[--str_size], set))
			return (str_size);
	return (str_size);
}

static char	*create_trimmed(const char *str, size_t start_index,
		size_t end_index)
{
	char	*buffer;
	size_t	size;
	size_t	i;
	size_t	j;

	if (!start_index && !end_index)
		size = 0;
	else
		size = end_index - start_index + 1;
	buffer = (char *)malloc(sizeof(char) * (size + 1));
	if (!buffer)
		return (NULL);
	i = 0;
	j = 0;
	while (*(str + i))
	{
		if (i >= start_index && i <= end_index)
			buffer[j++] = *(str + i);
		i++;
	}
	buffer[size] = '\0';
	return (buffer);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	size_t	start_index;
	size_t	end_index;

	if (!s1 || !set)
		return (NULL);
	start_index = 0;
	start_index = ft_getstart(s1, set);
	end_index = ft_getend(s1, set);
	res = create_trimmed(s1, start_index, end_index);
	return (res);
}
