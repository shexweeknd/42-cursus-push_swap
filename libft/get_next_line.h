/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:05:21 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 09:33:59 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include "libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_glist
{
	char			*str;
	struct s_glist	*next;
}					t_glist;

char				*get_next_line(int fd);

/*utils*/
t_glist				*lstnew(void *content);
int					bezero(char *str, size_t size);
void				recurse_free(t_glist **lst_ptr);
t_glist				*lstlast(t_glist *lst);
char				*create_tmp(t_glist *lst, int j, size_t size);

#endif
