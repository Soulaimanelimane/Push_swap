/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/23 14:49:00 by slimane           #+#    #+#             */
/*   Updated: 2024/11/11 13:56:30 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	lens;
	size_t	lend;
	size_t	i;

	lens = ft_strlen((char *)src);
	i = 0;
	if (dstsize == 0)
		return (lens);
	lend = ft_strlen(dst);
	if (lend >= dstsize)
		return (lens + dstsize);
	while (i < (dstsize - lend - 1) && src[i])
	{
		dst[lend + i] = src[i];
		i++;
	}
	dst[lend + i] = '\0';
	return (lend + lens);
}
