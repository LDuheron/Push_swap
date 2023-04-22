/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:47:59 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/17 17:29:02 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	countmove_top(int i, int len)
{
	int		j;
	int		move;

	if (i == 0)
		return (0);
	j = 0;
	move = 0;
	if (i <= len / 2)
		j = i;
	else if (i > len / 2)
		j = len - i + 1;
	while (j > 0)
	{
		if (i <= len / 2)
		{
			move++;
			j--;
		}
		if (i > len / 2)
		{
			move++;
			j--;
		}
	}
	return (move);
}

void	move_a(t_stack **stack_a, int nb)
{
	t_stack	*tmp;
	int		len;
	int		j;

	len = ft_lstsize(*stack_a);
	tmp = *stack_a;
	if (nb <= len / 2)
		j = nb;
	else if (nb > len / 2)
		j = len - nb;
	while (tmp && j > 0)
	{
		if (nb <= len / 2)
		{
			ft_ra(stack_a);
			j--;
		}
		if (nb > len / 2)
		{
			ft_rra(stack_a);
			j--;
		}
	}
}

void	move_b(t_stack **stack_b, int nb)
{
	t_stack	*tmp;
	int		len;
	int		j;

	len = ft_lstsize(*stack_b);
	tmp = *stack_b;
	if (nb <= len / 2)
		j = nb;
	else if (nb > len / 2)
		j = len - nb;
	while (tmp && j > 0)
	{
		if (nb <= len / 2)
		{
			ft_rb(stack_b);
			j--;
		}
		if (nb > len / 2)
		{
			ft_rrb(stack_b);
			j--;
		}
	}
}

int	total_move(t_stack **stack_a, t_stack **stack_b, int pos_b, int value_b)
{
	int		pos_in_a;
	int		move_a;
	int		move_b;
	int		moves;

	pos_in_a = find_position_in_stack(stack_a, value_b);
	move_b = countmove_top((pos_b), ft_lstsize(*stack_b));
	move_a = countmove_top(pos_in_a, ft_lstsize(*stack_a));
	moves = move_b + move_a;
	return (moves);
}
