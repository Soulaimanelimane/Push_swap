/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/16 22:03:19 by slimane           #+#    #+#             */
/*   Updated: 2025/02/07 18:38:34 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **lst, int flag)
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
	if (flag == 1)
		write(1, "sa\n", 3);
	else if (flag == 2)
		write(1, "sb\n", 3);
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
		write(1, "pa\n", 3);
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
		write(1, "pb\n", 3);
	}
}

void	rotate(t_stack **stack, int flag)
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
	if (flag == 1)
		write(1, "ra\n", 3);
	else if (flag == 2)
		write(1, "rb\n", 3);
}

void	reverse(t_stack **stack, int flag)
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
	if (flag == 1)
		write(1, "rra\n", 4);
	else if (flag == 2)
		write(1, "rrb\n", 4);
}
