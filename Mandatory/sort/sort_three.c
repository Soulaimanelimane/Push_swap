/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 05:34:49 by slimane           #+#    #+#             */
/*   Updated: 2025/01/30 21:29:56 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "sort.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	if (tmp->index == 0 && tmp->next->index == 1
		&& tmp->next->next->index == 2)
		return ;
	else if (tmp->index == 2 && tmp->next->index == 1
		&& tmp->next->next->index == 0)
	{
		(swap(stack, SA), reverse(stack, RRA));
	}
	else if (tmp->index == 1 && tmp->next->index == 0
		&& tmp->next->next->index == 2)
		swap(stack, SA);
	else if (tmp->index == 1 && tmp->next->index == 2
		&& tmp->next->next->index == 0)
		reverse(stack, RRA);
	else if (tmp->index == 0 && tmp->next->index == 2
		&& tmp->next->next->index == 1)
	{
		(swap(stack, SA), rotate(stack, RA));
	}
	else if (tmp->index == 2 && tmp->next->index == 0
		&& tmp->next->next->index == 1)
		rotate(stack, RA);
}
