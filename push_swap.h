/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:27:19 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 11:30:20 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <limits.h>
# include "./Actions/actions.h"

// Clean.c
void	ft_lstclear(t_stack **lst);
void	ft_putstr2(char *s);
void	error(t_stack **stack_a, t_stack **stack_b);

// Check_input.c
int		check_input(char **argv);

// Check_input_utils.c
int		is_digit(int c);
int		is_sign(char c);

// Insert_in_a.c
int		find_position_in_stack(t_stack **stack, int value_b);
int		get_the_best(t_stack **stack_a, t_stack **stack_b);
int		value_from_pos(t_stack **stack, int pos);
void	insert(t_stack **stack_a, t_stack **stack_b);

// Init_stacks.c
void	fill_index(t_stack **stack);
int		fill_stack(t_stack **stack, char **argv, int argc);

// Moves.c
int		countmove_top(int i, int len);
void	move_a(t_stack **stack_a, int nb);
void	move_b(t_stack **stack_b, int nb);
int		total_move(t_stack **stack_a, t_stack **stack_b,
			int pos_b, int value_b);

// Position.c
int		count_below_rank_m(t_stack **stack_a, int min, int max, float rank_m);
int		find_position_lowest(t_stack **stack);
int		find_position_middle(t_stack **stack, int number);
int		find_value_max(t_stack **stack);
int		find_value_min(t_stack **stack);

// Pre_sort.c
float	rank_moyen(float max, float min);
void	first_pre_sort(t_stack **stack_a, t_stack **stack_b, int min, int max);
void	pre_sort(t_stack **stack_a, t_stack **stack_b, int min, int max);

// Push_swap.c
void	push_swap(t_stack **stack_a, t_stack **stack_b);
void	sort_three(t_stack **stack);
void	sort_more(t_stack **stack_a, t_stack **stack_b);

// Push_swap_utils.c
long	ft_atol(const char *str);
int		ft_is_sorted(t_stack **stack_a);
void	ft_reorder(t_stack **stack);
int		ft_strlen(char *str);

#endif