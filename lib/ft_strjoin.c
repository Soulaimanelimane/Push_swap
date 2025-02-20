/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/27 10:34:43 by slimane           #+#    #+#             */
/*   Updated: 2024/11/13 15:21:32 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_strcat(char *dest, char *src)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(dest);
	while (src[i])
	{
		dest[len] = src[i];
		i++;
		len++;
	}
	dest[len] = '\0';
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*all_strs;

	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	all_strs = malloc((ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!all_strs)
		return (NULL);
	all_strs[0] = '\0';
	ft_strcat(all_strs, (char *)s1);
	ft_strcat(all_strs, (char *)s2);
	return (all_strs);
}
