/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:15:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/05 14:23:39 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "ft_printf.h"
# include "libft.h"
# include <limits.h>
# include <stddef.h>
// todo remove include de stdio.h
# include <stdio.h>
# include <stdlib.h>

typedef struct s_pile
{
	long			*value;
	struct s_pile	*next;
	struct s_pile	*prev;
	struct s_pile	*target;
	int				index;
	int				cost;
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

// algo turk utils
int					set_a_target(t_pile **a, t_pile **b);
int					set_b_target(t_pile **a, t_pile **b);
void				set_costs(t_pile *a, t_pile *b);
void				set_position(t_pile **pile, t_pile *target);
int					set_index(t_pile **pile);
t_pile				*get_min_cost_in(t_pile *pile);
t_pile				*get_min_value_in(t_pile *pile);

// fonctions utils
size_t				get_pile_size(t_pile *pile);
void				free_pile(t_pile **pile);
t_pile				*init_pile(long value);
void				ft_bezero(long *data, int pile_size);
void				ft_pile_delfirst(t_pile **a);

// fonctions utils pour debug
void				print_targets(t_pile **pile);
void				print_costs(t_pile **pile);
t_pile				*create_random_pile(size_t pile_size);
int					ft_pileadd_back(t_pile *elem, long number,
						int current_cursor, int last_cursor);

#endif
