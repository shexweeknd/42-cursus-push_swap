/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/24 16:18:39 by hramaros          #+#    #+#             */
/*   Updated: 2024/02/26 09:09:18 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*res_el;
	t_list	*first_el;
	void	*content;

	if (!lst)
		return (NULL);
	first_el = NULL;
	while (lst)
	{
		content = (*f)(lst->content);
		res_el = ft_lstnew(content);
		if (res_el == NULL)
		{
			(*del)(content);
			ft_lstclear(&first_el, (*del));
			return (NULL);
		}
		ft_lstadd_back(&first_el, res_el);
		lst = lst->next;
	}
	return (first_el);
}
