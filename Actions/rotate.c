/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:10:15 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/15 17:35:38 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "actions.h"

void	ft_ra(t_stack **stack_a)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->content = (*stack_a)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
		ft_remove_first_node(stack_a);
		ft_putstr("ra\n");
	}
}

void	ft_rb(t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->content = (*stack_b)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
		ft_remove_first_node(stack_b);
		ft_putstr("rb\n");
	}
}

void	ft_rr(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*stack_a) && (*stack_a)->next)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->content = (*stack_a)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_a, tmp);
		ft_remove_first_node(stack_a);
	}
	tmp = NULL;
	if ((*stack_b) && (*stack_b)->next)
	{
		tmp = malloc(sizeof(t_stack));
		tmp->content = (*stack_b)->content;
		tmp->next = NULL;
		ft_lstadd_back(stack_b, tmp);
		ft_remove_first_node(stack_b);
	}
	ft_putstr("rr\n");
}
