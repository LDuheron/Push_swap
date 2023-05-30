/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 13:22:36 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/30 15:17:12 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/push_swap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	while (s1[i] && s2[i] && s1[i] == s2[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

int	check_input_checker(char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		return (1);
	else if (ft_strcmp(str, "sb") == 0)
		return (1);
	else if (ft_strcmp(str, "ss") == 0)
		return (1);
	else if (ft_strcmp(str, "pa") == 0)
		return (1);
	else if (ft_strcmp(str, "pb") == 0)
		return (1);
	else if (ft_strcmp(str, "ra") == 0)
		return (1);
	else if (ft_strcmp(str, "rb") == 0)
		return (1);
	else if (ft_strcmp(str, "rr") == 0)
		return (1);
	else if (ft_strcmp(str, "rra") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr") == 0)
		return (1);
	ft_putstr2("Error\n");
	return (0);
}

void	apply_move(t_stack	**stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa") == 0)
		ft_sa(stack_a);
	else if (ft_strcmp(str, "sb") == 0)
		ft_sb(stack_b);
	else if (ft_strcmp(str, "ss") == 0)
		ft_ss(stack_a, stack_b);
	else if (ft_strcmp(str, "pa") == 0)
		ft_pa(stack_a, stack_b);
	else if (ft_strcmp(str, "pb") == 0)
		ft_pb(stack_a, stack_b);
	else if (ft_strcmp(str, "ra") == 0)
		ft_ra(stack_a);
	else if (ft_strcmp(str, "rb") == 0)
		ft_rb(stack_b);
	else if (ft_strcmp(str, "rr") == 0)
		ft_rr(stack_a, stack_b);
	else if (ft_strcmp(str, "rra") == 0)
		ft_rra(stack_a);
	else if (ft_strcmp(str, "rrb") == 0)
		ft_rrb(stack_b);
	else if (ft_strcmp(str, "rrr") == 0)
		ft_rrr(stack_a, stack_b);
}

void	print_result(t_stack **stack_a, t_stack **stack_b)
{
	if (ft_is_sorted(stack_a) == 1)
		ft_putstr("OK\n");
	if (ft_is_sorted(stack_a) == 1)
		ft_putstr("KO\n");
	if (stack_a)
		ft_lstclear(stack_a);
	if (stack_b)
		ft_lstclear(stack_b);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*line;

	stack_a = malloc(sizeof(t_stack **));
	stack_b = malloc(sizeof(t_stack **));
	stack_a = NULL;
	stack_b = NULL;
	line = NULL;
	if (fill_stack(&stack_a, argv, argc) == 1)
	{
		ft_putstr2("Error\n");
	}
	while (read(0, &line, 2))
	{
		if (check_input_checker(line) == 0)
			break ;
		apply_move(&stack_a, &stack_b, line);
	}
	print_result(&stack_a, &stack_b);
	return (0);
}
