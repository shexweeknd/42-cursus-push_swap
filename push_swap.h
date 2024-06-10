/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:15:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/10 11:45:42 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stddef.h>
# include <stdlib.h>

typedef struct s_pile
{
	long			value;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

// operations sur a
void				sa(t_pile **a);
void				pa(t_pile **a, t_pile **b);
void				ra(t_pile **a);
void				rra(t_pile **a);

// operations sur b
void				sb(t_pile **b);
void				pb(t_pile **b, t_pile **a);
void				rb(t_pile **b);
void				rrb(t_pile **a);

// operations sur ab
void				rr(t_pile **a, t_pile **b);
void				rrr(t_pile **a, t_pile **b);

#endif