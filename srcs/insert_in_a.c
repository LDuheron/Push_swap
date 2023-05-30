/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert_in_a.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 20:34:24 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/18 11:42:55 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_position_in_stack(t_stack **stack, int value_b)
{
	t_stack	*tmp;
	int		min;
	int		max;
	int		i;

	i = 0;
	min = find_value_min(stack);
	max = find_value_max(stack);
	tmp = *stack;
	if (value_b > max || value_b < min)
		i = find_position_lowest(stack);
	else
		i = find_position_middle(stack, value_b);
	return (i);
}

int	get_the_best(t_stack **stack_a, t_stack **stack_b)
{
	int		best;
	int		pos_best;
	int		pos_b;
	t_stack	*tmp;

	tmp = *stack_b;
	pos_b = tmp->index;
	pos_best = pos_b;
	best = total_move(stack_a, stack_b, pos_b, tmp->content);
	while (tmp)
	{
		if (best > total_move(stack_a, stack_b, tmp->index, tmp->content))
		{
			best = total_move(stack_a, stack_b, tmp->index, tmp->content);
			pos_best = tmp->index;
		}
		tmp = tmp->next;
	}
	return (pos_best);
}

int	value_from_pos(t_stack **stack, int pos)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp)
	{
		if (tmp->index == pos)
			return (tmp->content);
		tmp = tmp->next;
	}
	return (0);
}

void	insert(t_stack **stack_a, t_stack **stack_b)
{
	int	nb_move_a;
	int	pos_best_b;
	int	value_best_b;

	fill_index(stack_a);
	fill_index(stack_b);
	pos_best_b = get_the_best(stack_a, stack_b);
	value_best_b = value_from_pos(stack_b, pos_best_b);
	nb_move_a = find_position_in_stack(stack_a, value_best_b);
	move_a(stack_a, nb_move_a);
	move_b(stack_b, pos_best_b);
	ft_pa(stack_a, stack_b);
}
