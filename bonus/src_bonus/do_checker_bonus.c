/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   do_checker_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 18:06:06 by slimane           #+#    #+#             */
/*   Updated: 2025/02/10 01:16:11 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	check_cmp(t_stack **stack_a, t_stack **stack_b, char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		swap(stack_a);
	else if (ft_strcmp(str, "sb\n") == 0)
		swap(stack_b);
	else if (ft_strcmp(str, "pa\n") == 0)
		push(stack_a, stack_b, PA);
	else if (ft_strcmp(str, "pb\n") == 0)
		push(stack_a, stack_b, PB);
	else if (ft_strcmp(str, "ra\n") == 0)
		rotate(stack_a);
	else if (ft_strcmp(str, "rb\n") == 0)
		rotate(stack_b);
	else if (ft_strcmp(str, "rra\n") == 0)
		reverse(stack_a);
	else if (ft_strcmp(str, "rrb\n") == 0)
		reverse(stack_b);
	else if (ft_strcmp(str, "ss\n") == 0)
		group_ins_2(stack_a, stack_b, SS);
	else if (ft_strcmp(str, "rr\n") == 0)
		group_ins_2(stack_a, stack_b, RR);
	else if (ft_strcmp(str, "rrr\n") == 0)
		group_ins_2(stack_a, stack_b, RRR);
}

int	ft_cheker(t_stack **stack_a, t_stack **stack_b, t_checker **list)
{
	char		*str;
	t_checker	*tmp;

	str = NULL;
	tmp = *list;
	while (tmp && tmp->data != NULL)
	{
		str = tmp->data;
		check_cmp(stack_a, stack_b, str);
		tmp = tmp->next;
	}
	return (1);
}
