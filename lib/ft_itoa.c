/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 23:58:00 by slimane           #+#    #+#             */
/*   Updated: 2024/11/14 12:02:46 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sign(long *n)
{
	if (*n < 0)
	{
		*n *= -1;
		return (-1);
	}
	return (1);
}

static int	ft_len_int(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n *= -1;
		i++;
	}
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*p;
	long	nbr;
	int		sign;
	int		len;

	nbr = n;
	len = ft_len_int(nbr);
	p = malloc(len + 1 * sizeof(char));
	if (!p)
		return (NULL);
	sign = check_sign(&nbr);
	if (nbr == 0)
		p[0] = '0';
	p[len--] = '\0';
	while (nbr)
	{
		p[len--] = (nbr % 10) + 48;
		nbr /= 10;
	}
	if (sign < 0)
		p[0] = '-';
	return (p);
}
