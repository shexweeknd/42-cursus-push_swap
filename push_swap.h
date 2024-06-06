/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42antananari    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:15:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/06/06 09:55:34 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stddef.h>
# include <stdlib.h>

typedef struct s_pile
{
	int				value;
	struct s_pile	*next;
	struct s_pile	*prev;
}					t_pile;

// operations sur a
t_pile				*sa(t_pile *first_elem);
t_pile				*pa(t_pile *a, t_pile *b);
t_pile				*ra(t_pile *first_elem);
t_pile				*rra(t_pile *first_elem);

// operations sur b
t_pile				*sb(t_pile *first_elem);
t_pile				*pb(t_pile *first_elem);
t_pile				*rb(t_pile *first_elem);
t_pile				*rrb(t_pile *first_elem);

// operations sur ab
t_pile				*rr(t_pile *first_elem);
t_pile				*rrr(t_pile *first_elem);

#endif