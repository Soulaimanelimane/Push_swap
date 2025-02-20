/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_sorting_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 08:23:24 by slimane           #+#    #+#             */
/*   Updated: 2025/02/19 11:41:11 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int	is_sorted(t_stack *stack, t_stack *stack_b)
{
	t_stack	*tmp;

	if (!stack || stack_b)
	{
		ft_lstclear(&stack);
		ft_lstclear(&stack_b);
		return (0);
	}
	tmp = stack;
	while (stack && stack->next != NULL)
	{
		if (stack->content > stack->next->content)
		{
			ft_lstclear(&stack);
			ft_lstclear(&stack_b);
			return (0);
		}
		stack = stack->next;
	}
	ft_lstclear(&tmp);
	ft_lstclear(&stack_b);
	return (1);
}
