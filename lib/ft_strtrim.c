/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/31 12:14:20 by slimane           #+#    #+#             */
/*   Updated: 2024/11/16 11:58:17 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_sep(char str, char *sep)
{
	int	i;

	i = 0;
	while (sep[i])
	{
		if (sep[i] == str)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	len;
	size_t	i;

	i = 0;
	if (!s1)
		return (NULL);
	if (!set)
		return (ft_strdup(s1));
	if (ft_strlen(s1) == 0)
		return (ft_strdup(""));
	while (s1[i] && check_sep((char)s1[i], (char *)set))
		i++;
	len = ft_strlen(s1);
	while (len > i && check_sep(s1[len - 1], (char *)set))
		len--;
	if (len > i)
		return (ft_substr(s1, i, (len - i)));
	return (ft_substr(s1, i, 0));
}
