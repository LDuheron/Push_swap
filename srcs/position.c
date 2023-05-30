/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/28 15:54:51 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/17 16:54:34 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	count_below_rank_m(t_stack **stack_a, int min, int max, float rank_m)
{
	int		i;
	int		denominator;
	t_stack	*tmp;

	i = 0;
	denominator = (((float)max - (float)min) + 1);
	tmp = *stack_a;
	while (tmp->next)
	{
		if (rank_m > (tmp->content - (float)min) / denominator)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

int	find_position_lowest(t_stack **stack)
{
	t_stack	*tmp;
	int		lowest_pos;
	int		lowest_value;

	tmp = *stack;
	lowest_pos = tmp->index;
	lowest_value = tmp->content;
	while (tmp)
	{
		if (lowest_value > tmp->content)
		{
			lowest_value = tmp->content;
			lowest_pos = tmp->index;
		}
		tmp = tmp->next;
	}
	return (lowest_pos);
}

int	find_position_middle(t_stack **stack, int number)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack;
	i = 0;
	if (number < tmp->content && number < tmp->next->content
		&& number > ft_lstlast(*stack)->content)
		return (0);
	while (tmp && tmp->next)
	{
		i++;
		if (number > tmp->content && number < tmp->next->content)
			break ;
		tmp = tmp->next;
	}
	return (i);
}

int	find_value_max(t_stack **stack)
{
	t_stack	*tmp;
	int		max;

	tmp = *stack;
	max = tmp->content;
	while (tmp)
	{
		if (tmp->content > max)
			max = tmp->content;
		tmp = tmp->next;
	}
	return (max);
}

int	find_value_min(t_stack **stack)
{
	t_stack	*tmp;
	int		low;

	tmp = *stack;
	low = tmp->content;
	while (tmp)
	{
		if (tmp->content < low)
			low = tmp->content;
		tmp = tmp->next;
	}
	return (low);
}
