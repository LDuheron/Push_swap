/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/10 19:07:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/30 13:55:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_last_to_first(t_stack **stack)
{
	t_stack	*tmp;

	tmp = NULL;
	if ((*stack) && (*stack)->next)
	{
		tmp = *stack;
		while (tmp->next != NULL)
			tmp = tmp->next;
		ft_lstadd_front(stack, ft_lstnew(tmp->content));
	}
}

void	ft_remove_first_node(t_stack **stack)
{
	t_stack	*head;

	head = NULL;
	head = *stack;
	if (stack)
		*stack = (*stack)->next;
	free(head);
}

void	ft_remove_last_node(t_stack **stack)
{
	t_stack	*tmp;		

	tmp = NULL;
	tmp = *stack;
	while (tmp->next->next != NULL)
		tmp = tmp->next;
	free(tmp->next);
	tmp->next = NULL;
}

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
}
