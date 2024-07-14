/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramaros <hramaros@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/23 07:15:37 by hramaros          #+#    #+#             */
/*   Updated: 2024/07/14 09:46:51 by hramaros         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <limits.h>
# include <stddef.h>
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
	int				family;
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
void				pseudo_ra(t_pile **a);
void				pseudo_rb(t_pile **b);
void				rr(t_pile **a, t_pile **b);
void				pseudo_rra(t_pile **a);
void				pseudo_rrb(t_pile **b);
void				rrr(t_pile **a, t_pile **b);

// algo turk utils
int					set_b_target(t_pile **a, t_pile **b);
void				set_costs(t_pile *a, t_pile *b);
int					set_position(t_pile **pile, t_pile *to_put_in_top);
int					set_index(t_pile **pile);
t_pile				*get_min_target_from_array(t_pile *pile, long *tab,
						int array_size);
t_pile				*get_max_target_from_array(t_pile *pile, long *tab,
						int array_size);
t_pile				*get_min_cost_in(t_pile *pile, int family_id);
t_pile				*get_min_value_in(t_pile *pile);
t_pile				*get_max_value_in(t_pile *pile);

// fonctions pour parse les donnees en entree
t_pile				*verify_argv(char **argv);
int					ft_has_greater_than(t_pile *pile, long long to_compare);
int					ft_has_duplicates(t_pile *pile);
int					ft_is_sorted(t_pile *pile);

// fonctions utils de l'algorithme principal de push_swap
void				mini_sort(t_pile **a);
void				put_in_b(t_pile **a, t_pile **b);
void				send_back_to_a(t_pile **a, t_pile **b);
void				last_round(t_pile **a, t_pile *min);

// fonctions utils
size_t				get_pile_size(t_pile *pile);
void				free_pile(t_pile **pile);
t_pile				*init_pile(long value);
void				ft_bezero(long *data, int pile_size);
void				ft_pile_delfirst(t_pile **a);
int					ft_pileadd_back(t_pile *elem, long number,
						int current_cursor, int last_cursor);
t_pile				*get_last_elem(t_pile *pile);
size_t				get_args_numbers(char *argv);

// fonctions utils concernant les familles
int					get_max_family_id(t_pile *pile);
void				set_family(t_pile *pile, int first_family_id,
						int max_members);
int					is_family_set(t_pile *pile);
void				push_family_to_b(int first_family_id, t_pile **a,
						t_pile **b);
int					is_any_fammemb(t_pile *pile, int id);
void				set_family_id(long value, t_pile *pile, int family_id);
int					get_numbers_of_family(t_pile **a);

// fonctions de fix pour les familles restantes
void				fix_first_members(t_pile *pile);
void				fix_last_members(t_pile *pile);

// fonctions utils pour debug
void				print_targets(t_pile **pile);
void				print_costs(t_pile **pile);
void				print_index(t_pile **pile);
void				print_pile(t_pile **pile);
t_pile				*create_random_pile(size_t pile_size);
void				print_families(t_pile **pile);
void				print_one_elem(t_pile *pile);

#endif
