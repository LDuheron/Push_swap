/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/10 22:26:43 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 11:05:21 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	if (fill_stack(&stack_a, argv, argc) == 0)
		error(&stack_a, &stack_b);
	else
	{
		fill_index(&stack_a);
		if (ft_is_sorted(&stack_a) == 0)
			push_swap(&stack_a, &stack_b);
		ft_lstclear(&stack_a);
		ft_lstclear(&stack_b);
	}
	return (0);
}
