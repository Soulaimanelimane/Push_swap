/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 10:11:51 by slimane           #+#    #+#             */
/*   Updated: 2025/02/17 20:44:30 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	check_mins(int *check, const char *str, int *i, long long *sign)
{
	int	d;
	int	count;

	count = 0;
	d = *i;
	while (str[*i] == '+' || str[*i] == '-')
	{
		if ((str[d] == '-' || str[d] == '+')
			&& !(str[d + 1] >= '0' && str[d + 1] <= '9'))
		{
			*check = 1;
			return ;
		}
		if (count > 0)
		{
			*check = 1;
			return ;
		}
		if (str[*i] == '-')
			*sign = *sign * -1;
		(*i)++;
		count++;
	}
}

int	ft_atoi(const char *str, int *check)
{
	long long	result;
	long long	sign;
	int			i;

	result = 0;
	sign = 1;
	i = 0;
	check_mins(check, &str[i], &i, &sign);
	if (*check == 1)
		return (*check);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if ((result * sign) > 2147483647 || (result * sign) < -2147483648)
			return (*check = 1, *check);
		i++;
	}
	if (str[i] != '\0')
		return (*check = 1, *check);
	return (result * sign);
}
