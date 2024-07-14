/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 09:18:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/29 15:23:23 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_isset(char *str, char *set)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (*(str + i))
	{
		j = 0;
		while (*(set + j))
		{
			if (*(str + i) == *(set + j))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static size_t	ft_get_occ(const char *str)
{
	char	*set;
	size_t	i;
	size_t	count;

	set = "cspdiuxX%";
	i = 0;
	count = 0;
	while (*(str + i))
	{
		if (*(str + i) == '%' && ft_isset(*(str + i + 1), set))
			count++;
		i++;
	}
	return (0);
}

static void	ft_free(char **buffer)
{
	int	count;

	count = 0;
	while (*(buffer + count))
	{
		free(*(buffer + count));
		count++;
	}
	free(buffer);
	return ;
}
