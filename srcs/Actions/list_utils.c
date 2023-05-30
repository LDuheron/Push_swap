/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lduheron <lduheron@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/06 14:30:00 by lduheron          #+#    #+#             */
/*   Updated: 2023/05/30 13:55:57 by lduheron         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_stack *lst)
{
	int	size;

	size = 0;
	if (!(lst))
		return (0);
	while (lst)
	{
		lst = lst->next;
		size++;
	}
	return (size);
}

t_stack	*ft_lstlast(t_stack *lst)
{
	t_stack	*tmp;

	tmp = NULL;
	if (!(lst))
		return (NULL);
	tmp = lst;
	while (tmp->next != NULL)
		tmp = tmp->next;
	return (tmp);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!(*lst))
		*lst = new;
	else
	{
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = new;
	}
}

void	ft_lstadd_front(t_stack **lst, t_stack *new)
{
	if (lst == NULL)
		*lst = new;
	new->next = *lst;
	*lst = new;
}

t_stack	*ft_lstnew(int content)
{
	t_stack	*new_elem;

	new_elem = malloc (sizeof(t_stack));
	if (!new_elem)
		return (NULL);
	new_elem->index = 0;
	new_elem->content = content;
	new_elem->next = NULL;
	return (new_elem);
}
