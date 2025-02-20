/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 23:01:48 by slimane           #+#    #+#             */
/*   Updated: 2025/02/15 22:51:29 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

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
