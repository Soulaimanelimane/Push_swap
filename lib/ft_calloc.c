/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/26 15:52:14 by slimane           #+#    #+#             */
/*   Updated: 2024/11/14 23:38:30 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;
	size_t	len;

	if (size != 0 && count > 1222 / size)
		return (NULL);
	len = count * size;
	p = malloc(len);
	if (p)
		ft_bzero(p, len);
	return (p);
}
