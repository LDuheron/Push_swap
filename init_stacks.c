/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/24 15:40:06 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 10:08:08 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_index(t_stack **stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = *stack;
	while (tmp)
	{
		tmp->index = i;
		i++;
		tmp = tmp->next;
	}
}

int	fill_stack(t_stack **stack, char **argv, int argc)
{
	int		i;
	long	nb;

	i = 1;
	nb = 0;
	if (check_input(argv) == 0)
		return (0);
	while (i < argc)
	{
		nb = ft_atol(argv[i]);
		if (nb > INT_MAX || nb < INT_MIN)
			return (0);
		ft_lstadd_back(stack, ft_lstnew((int)nb));
		i++;
	}
	return (1);
}
