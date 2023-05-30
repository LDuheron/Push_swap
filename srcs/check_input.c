/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 17:37:59 by lduheron          #+#    #+#             */
/*   Updated: 2023/04/22 11:49:51 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp_nb(const char *s1, const char *s2)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (s1[i] == '+')
	{
		if (s2[j] != '+')
			i++;
	}
	else
	{
		if (s2[j] == '+')
			j++;
	}
	while (s1[i] && s2[j] && s1[i] == s2[j])
	{	
		i++;
		j++;
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[j]);
}

int	check_duplicate(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i] != NULL)
	{
		j = 1;
		while (argv[j])
		{
			if (i != j && ft_strcmp_nb(argv[i], argv[j]) == 0)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

int	check_number(char *input)
{
	int	i;

	i = 0;
	if (is_sign(input[i]) && input[i + 1] != '\0')
		i++;
	while (input[i] && is_digit(input[i]) == 1)
		i++;
	if (is_digit(input[i]) == 0 && input[i] != '\0')
		return (0);
	return (1);
}

int	check_zero(char *input)
{
	int	i;

	i = 0;
	if (is_sign(input[i]) == 1)
		i++;
	while (input[i] && input[i] == '0')
		i++;
	if (input[i] != '\0')
		return (0);
	return (1);
}

int	check_input(char **argv)
{
	int	i;
	int	zero;

	i = 1;
	zero = 0;
	if (check_duplicate(argv) == 0)
		return (0);
	while (argv[i])
	{
		if (check_number(argv[i]) == 0)
			return (0);
		zero += check_zero(argv[i]);
		if (zero > 1)
			return (0);
		i++;
	}
	return (1);
}
