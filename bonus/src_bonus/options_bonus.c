/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:19 by slimane           #+#    #+#             */
/*   Updated: 2025/02/10 03:37:16 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	swap(t_stack **lst)
{
	t_stack	*list;
	t_stack	*list2;
	int		size;

	size = ft_lstsize_lib(*lst);
	if (size < 2)
		return ;
	list = *lst;
	list2 = (*lst)->next;
	list->next = list2->next;
	list2->next = list;
	*lst = list2;
}

void	push(t_stack **stack_a, t_stack **stack_b, int flag)
{
	t_stack	*tmp;

	tmp = NULL;
	if (flag == 1)
	{
		if (!*stack_b)
			return ;
		tmp = *stack_b;
		*stack_b = (*stack_b)->next;
		tmp->next = NULL;
		tmp->next = *stack_a;
		*stack_a = tmp;
	}
	else if (flag == 0)
	{
		if (!*stack_a)
			return ;
		tmp = *stack_a;
		*stack_a = (*stack_a)->next;
		tmp->next = NULL;
		tmp->next = *stack_b;
		*stack_b = tmp;
	}
}

void	rotate(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	int		size;

	size = ft_lstsize_lib(*stack);
	if (size < 2)
		return ;
	tmp = *stack;
	last = *stack;
	while (last->next != NULL)
	{
		last = last->next;
	}
	last->next = tmp;
	*stack = (*stack)->next;
	tmp->next = NULL;
}

void	reverse(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*last;
	int		size;

	size = ft_lstsize_lib(*stack);
	if (size < 2)
		return ;
	tmp = *stack;
	while (tmp && tmp->next->next)
		tmp = tmp->next;
	last = tmp->next;
	last->next = *stack;
	*stack = last;
	tmp->next = NULL;
}

void	group_ins_2(t_stack **stack_a, t_stack **stack_b, int flag)
{
	if (flag == RR)
	{
		rotate(stack_a);
		rotate(stack_b);
	}
	else if (flag == RRR)
	{
		reverse(stack_a);
		reverse(stack_b);
	}
	else if (flag == SS)
	{
		swap(stack_a);
		swap(stack_b);
	}
}
