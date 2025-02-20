/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:01:48 by slimane           #+#    #+#             */
/*   Updated: 2025/02/15 22:55:18 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize_lib(t_stack *lst)
{
	int	count;

	count = 0;
	if (lst == NULL)
		return (count);
	while (lst != NULL)
	{
		lst = lst->next;
		count++;
	}
	return (count);
}
