/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:28:42 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/15 17:35:38 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	ft_rra(t_stack **stack_a)
{
	if ((*stack_a) && (*stack_a)->next)
	{
		ft_last_to_first(stack_a);
		ft_remove_last_node(stack_a);
		ft_putstr("rra\n");
	}
}

void	ft_rrb(t_stack **stack_b)
{
	if ((*stack_b) && (*stack_b)->next)
	{
		ft_last_to_first(stack_b);
		ft_remove_last_node(stack_b);
		ft_putstr("rrb\n");
	}
}

void	ft_rrr(t_stack **stack_a, t_stack **stack_b)
{
	ft_last_to_first(stack_a);
	ft_remove_last_node(stack_a);
	ft_last_to_first(stack_b);
	ft_remove_last_node(stack_b);
	ft_putstr("rrr\n");
}
