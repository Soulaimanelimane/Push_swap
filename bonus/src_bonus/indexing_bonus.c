/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   indexing_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/17 15:24:31 by slimane           #+#    #+#             */
/*   Updated: 2025/02/10 01:16:11 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_index(t_stack **stack)
{
	t_stack	*tmp;
	t_stack	*swap;
	int		i;

	i = 0;
	if (!stack)
		return ;
	tmp = *stack;
	while (tmp)
	{
		i = 0;
		swap = *stack;
		while (swap != NULL)
		{
			if (swap->content < tmp->content)
				i++;
			swap = swap->next;
		}
		tmp->index = i;
		tmp = tmp->next;
	}
}
