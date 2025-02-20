/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/18 22:59:25 by slimane           #+#    #+#             */
/*   Updated: 2025/01/31 02:10:26 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*tmp;
	int		position;

	tmp = *stack_a;
	position = 0;
	if (tmp->index == 0 && tmp->next->index == 1 && tmp->next->next->index == 2
		&& tmp->next->next->next->index == 3
		&& tmp->next->next->next->next->index == 4)
		return ;
	while (tmp && tmp->index != 0)
	{
		position++;
		tmp = tmp->next;
	}
	while ((*stack_a)->index != 0)
	{
		if (position <= 3)
			rotate(stack_a, RA);
		else
			reverse(stack_a, RRA);
	}
	(push(stack_a, stack_b, PB), ft_index(stack_a));
	sort_four(stack_a, stack_b);
	push(stack_a, stack_b, PA);
	ft_index(stack_a);
}
