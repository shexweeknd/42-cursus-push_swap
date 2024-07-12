/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_fixer.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:03:33 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/12 11:27:21 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fix_first_members(t_pile *pile)
{
	int		fam_id;
	t_pile	*last_member;
	t_pile	*first_elem;

	first_elem = pile;
	fam_id = 0;
	while (pile)
	{
		if (pile->family != 0)
		{
			fam_id = pile->family;
			last_member = pile;
			break ;
		}
		pile = pile->next;
	}
	while (first_elem != last_member)
	{
		first_elem->family = fam_id;
		first_elem = first_elem->next;
	}
}

void	fix_last_members(t_pile *pile)
{
	int		fam_id;
	t_pile	*last_member;
	t_pile	*last_elem;
	t_pile	*curr;

	last_elem = get_last_elem(pile);
	curr = last_elem;
	while (curr)
	{
		if (curr->family != 0)
		{
			fam_id = curr->family;
			last_member = curr;
			break ;
		}
		curr = curr->prev;
	}
	while (last_elem != last_member)
	{
		last_elem->family = fam_id;
		last_elem = last_elem->prev;
	}
}
