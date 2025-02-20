/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 05:53:53 by slimane           #+#    #+#             */
/*   Updated: 2025/02/13 11:14:57 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_stack	*new_node(long n)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return (NULL);
	new->content = n;
	new->index = 0;
	new->next = NULL;
	return (new);
}

void	add_back(t_stack **stack, t_stack *new)
{
	t_stack	*last;

	if (!new)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

t_stack	*creating_for_tr(int *numbers, int len)
{
	t_stack	*lst;
	int		i;
	t_stack	*num;

	i = 0;
	lst = new_node(numbers[i]);
	if (!lst)
		return (ft_lstclear(&lst), NULL);
	i++;
	while (i < len)
	{
		num = new_node(numbers[i]);
		if (!num)
			return (ft_lstclear(&lst), NULL);
		add_back(&lst, num);
		i++;
	}
	return (lst);
}
