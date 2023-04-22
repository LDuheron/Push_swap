/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pre_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 17:17:18 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 16:45:27 by lduheron         ###   ########.fr       */
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
	rank_m = rank_moyen((float)max, (float)min) / 2;
	i = count_below_rank_m(stack_a, min, max, rank_m);
	while (i > 0 && tmp->content && ft_lstsize(*stack_a) >= 4)
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
	while (i > 0 && tmp->content && ft_lstsize(*stack_a) >= 4)
	{
		if (rank_m > (tmp->content - (float)min) / (((float)max
					- (float)min) + 1))
		{
			ft_pb(stack_a, stack_b);
			i--;
		}
		else if ((*stack_b)->content > ft_lstlast(*stack_b)->content
			&& ft_lstsize(*stack_b) > 2)
			ft_rr(stack_a, stack_b);
		else
			ft_ra(stack_a);
		tmp = (*stack_a);
	}
}
