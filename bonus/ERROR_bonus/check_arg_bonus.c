/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 02:18:12 by slimane           #+#    #+#             */
/*   Updated: 2025/02/11 16:24:55 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

int	dup_int(int *lst, int i, int nb)
{
	int	j;
	int	count;

	j = 0;
	count = 0;
	while (j < nb)
	{
		if (lst[j] == i)
			count++;
		j++;
	}
	return (count);
}

int	check_arg(int *lst, int nb)
{
	int	i;

	i = 0;
	while (nb > i)
	{
		if (dup_int(lst, lst[i], nb) > 1)
			return (-1);
		i++;
	}
	return (0);
}
