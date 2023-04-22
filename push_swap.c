/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:33:12 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 16:28:03 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = find_value_max(stack);
	if (ft_is_sorted(stack) == 0)
	{
		tmp = *stack;
		if (tmp->content == max)
			ft_ra(stack);
		else if (tmp->next->content == max)
			ft_rra(stack);
		tmp = *stack;
		if (tmp->content > tmp->next->content)
			ft_sa(stack);
	}
}

void	sort_more(t_stack **stack_a, t_stack **stack_b)
{
	int		min;
	int		max;

	min = find_value_min(stack_a);
	max = find_value_max(stack_a);
	first_pre_sort(stack_a, stack_b, min, max);
	while (ft_lstsize(*stack_a) > 3)
	{
		if (ft_lstsize(*stack_a) == 4)
		{
			ft_pb(stack_a, stack_b);
			break ;
		}
		min = find_value_min(stack_a);
		max = find_value_max(stack_a);
		pre_sort(stack_a, stack_b, min, max);
	}
	sort_three(stack_a);
	while (ft_lstsize(*stack_b) != 0)
		insert(stack_a, stack_b);
	ft_reorder(stack_a);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	size = ft_lstsize(*stack_a);
	if (size == 2 && ft_is_sorted(stack_a) == 0)
		ft_sa(stack_a);
	else if (size == 3)
		sort_three(stack_a);
	else
		sort_more(stack_a, stack_b);
}
