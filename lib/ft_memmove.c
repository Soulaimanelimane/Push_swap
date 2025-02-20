/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/25 22:46:00 by slimane           #+#    #+#             */
/*   Updated: 2024/11/13 14:04:53 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*d;
	unsigned char	*s;
	size_t			i;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	i = 0;
	if (d == s)
		return (dst);
	if (d < s)
	{
		while (len)
		{
			d[i] = s[i];
			i++;
			len--;
		}
	}
	else if (d > s)
	{
		while (len--)
			d[len] = s[len];
	}
	return (d);
}
