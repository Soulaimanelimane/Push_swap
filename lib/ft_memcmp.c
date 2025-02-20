/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 12:28:32 by slimane           #+#    #+#             */
/*   Updated: 2024/11/04 00:16:07 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	int				res;

	res = 0;
	str1 = (unsigned char *)s1;
	str2 = (unsigned char *)s2;
	while (n)
	{
		res = (*str1++) - (*str2++);
		if (res)
			return (res);
		n--;
	}
	return (0);
}
