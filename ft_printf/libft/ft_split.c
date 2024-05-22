/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 19:23:47 by hramaros          #+#    #+#             */
/*   Updated: 2024/05/07 07:15:00 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(const char *s, unsigned char c)
{
	size_t	count;

	count = 0;
	if (!*s)
		return (0);
	while (*s == c)
		s++;
	while (*s)
	{
		if (*s != c)
		{
			count++;
			while (*s != c && *s)
				s++;
		}
		else
			while (*s && *s == c)
				s++;
	}
	return (count);
}

static char	*ft_firstword(char *str, char c)
{
	char	*word;
	int		f_word_len;
	int		i;

	f_word_len = 0;
	while (str[f_word_len] == c)
		str++;
	while (str[f_word_len] != c && str[f_word_len] != '\0')
		f_word_len++;
	word = (char *)malloc(sizeof(char) * (f_word_len + 1));
	if (!word)
		return (NULL);
	i = 0;
	while (*str != c && *str != '\0')
	{
		if (*str != c)
			word[i++] = *str;
		str++;
	}
	word[f_word_len] = '\0';
	return (word);
}

static int	ft_decalage(const char *str, char c, int position)
{
	while (str[position] == c)
		position++;
	while (str[position] != '\0')
	{
		if (str[position] == c && str[position + 1] != c)
		{
			position++;
			break ;
		}
		position++;
	}
	return (position);
}

static void	ft_free(char **buffer)
{
	int	i;

	i = 0;
	while (*(buffer + i))
		free(*(buffer + i++));
	free(buffer);
}

char	**ft_split(char const *s, char c)
{
	char	**buffer2d;
	size_t	word_count;
	size_t	i;
	int		position;

	if (!s)
		return (NULL);
	word_count = ft_word_count(s, c);
	buffer2d = (char **)malloc(sizeof(char *) * (word_count + 1));
	if (!buffer2d)
		return (NULL);
	i = 0;
	position = 0;
	while (i < word_count)
	{
		buffer2d[i] = ft_firstword((char *)(s + position), c);
		if (!buffer2d[i++])
		{
			ft_free(buffer2d);
			return (NULL);
		}
		position = ft_decalage(s, c, position);
	}
	buffer2d[word_count] = NULL;
	return (buffer2d);
}
