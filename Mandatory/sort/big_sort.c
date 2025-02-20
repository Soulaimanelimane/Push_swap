/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 00:41:33 by slimane           #+#    #+#             */
/*   Updated: 2025/02/13 08:33:03 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

int	ft_chek_tow(t_stack *head_b, int size)
{
	int	count;
	int	espas;

	count = 0;
	while (head_b && head_b->next)
	{
		espas = head_b->index - head_b->next->index;
		if (espas == 2 || espas == 3 || espas == 4)
			count++;
		head_b = head_b->next;
	}
	if (count * 10 >= size * 6)
		return (1);
	return (0);
}

int	get_positon(t_stack **stack)
{
	int		position;
	int		max;
	t_stack	*tmp;

	if (!stack)
		return (-1);
	position = 0;
	tmp = *stack;
	max = -2147483648;
	while (*stack)
	{
		if ((*stack)->content > max)
			max = (*stack)->content;
		*stack = (*stack)->next;
	}
	while (tmp->content != max)
	{
		position++;
		tmp = tmp->next;
	}
	return (position);
}

void	secend_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int		pos;
	t_stack	*tmp;

	pos = 0;
	tmp = *stack_b;
	while (size > 0)
	{
		tmp = *stack_b;
		pos = get_positon(&tmp);
		if (pos == -1)
			return ;
		if (pos <= (size / 2))
		{
			while (pos--)
				rotate(stack_b, RB);
		}
		else
		{
			while (pos++ < size)
				reverse(stack_b, RRB);
		}
		size--;
		push(stack_a, stack_b, PA);
	}
}

void	big_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	range;
	int	fail;

	range = 33;
	if (size <= 100)
		range = 16;
	i = 0;
	fail = ft_chek_tow(*stack_a, size);
	while ((*stack_a) != NULL)
	{
		if ((*stack_a)->index <= i)
		{
			push(stack_a, stack_b, PB);
			i++;
		}
		else if ((*stack_a)->index <= (i + range))
			(push(stack_a, stack_b, PB), rotate(stack_b, RB), i++);
		else if (fail == 1)
			reverse(stack_a, RRA);
		else
			rotate(stack_a, RA);
	}
	secend_sort(stack_a, stack_b, size);
}
