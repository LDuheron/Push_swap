/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:18 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/24 13:03:15 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

float	rank_moyen(float max, float min)
{
	float	rank;

	rank = (((max - (float)min) / (((float)max - (float)min) + 1)) / 2);
	return (rank);
}

void	first_pre_sort(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	t_stack	*tmp;
	int		i;
	float	rank_m;

	tmp = *stack_a;
	rank_m = rank_moyen((float)max, (float)min) / 1.5;
	i = count_below_rank_m(stack_a, min, max, rank_m);
	while (i > 0 && ft_lstsize(*stack_a) >= 4)
	{
		if (rank_m > (tmp->content - (float)min) / ((float)max
				- (float)min + 1))
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
		else
			ft_ra(stack_a);
		tmp = (*stack_a);
	}
}

void	pre_sort(t_stack **stack_a, t_stack **stack_b, int min, int max)
{
	t_stack	*tmp;
	float	rank_m;
	int		i;

	rank_m = rank_moyen((float)max, (float)min);
	tmp = *stack_a;
	i = count_below_rank_m(stack_a, min, max, rank_m);
	while (i > 0 && ft_lstsize(*stack_a) > 3)
	{
		if (rank_m > ((float)tmp->content
				- (float)min) / (((float)max - (float)min) + 1))
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
		else
			ft_ra(stack_a);
		tmp = (*stack_a);
	}
}
