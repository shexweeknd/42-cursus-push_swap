/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 07:23:17 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 09:32:54 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static size_t	c_count(t_glist *lst)
{
	size_t	count;
	size_t	i;

	count = 0;
	while (lst)
	{
		i = 0;
		while (lst->str[i] && lst->str[i] != '\n')
			i++;
		count += i;
		lst = lst->next;
	}
	return (count);
}

static int	nl_number(char *str)
{
	int	occur;

	occur = 0;
	while (*str)
		if (*str++ == '\n')
			occur++;
	return (occur);
}

static size_t	strlen(const char *s)
{
	int	count;

	count = 0;
	while (s[count])
		count++;
	return (count);
}

static void	fullfill(t_glist **lst_ptr, t_glist *premier, char *buffer)
{
	int		i;
	int		j;
	char	*tmp;

	i = 0;
	while (premier && premier->str)
	{
		j = 0;
		while (premier->str[j])
		{
			buffer[i++] = premier->str[j];
			if (premier->str[j++] == '\n')
				break ;
		}
		if (!premier->next)
			break ;
		premier = premier->next;
	}
	tmp = create_tmp(premier, j, strlen(&premier->str[j]));
	recurse_free(lst_ptr);
	if (tmp != NULL)
	{
		*lst_ptr = lstnew(tmp);
		free(tmp);
	}
}

char	*get_next_line(int fd)
{
	static t_glist	*premier;
	char			*buffer;

	if (!BUFFER_SIZE || (fd < 0 || fd >= 10))
		return (NULL);
	buffer = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	bezero(buffer, BUFFER_SIZE);
	if (premier == NULL)
	{
		if (read(fd, buffer, BUFFER_SIZE) <= 0)
		{
			free(buffer);
			return (NULL);
		}
		premier = lstnew(buffer);
	}
	while (!nl_number(premier->str) && (nl_number(buffer) == 0)
		&& bezero(buffer, BUFFER_SIZE) && read(fd, buffer, BUFFER_SIZE) != 0)
		lstlast(premier)->next = lstnew(buffer);
	free(buffer);
	buffer = (char *)malloc(sizeof(char) * (c_count(premier) + 2));
	bezero(buffer, c_count(premier) + 1);
	fullfill(&premier, premier, buffer);
	return (buffer);
}
