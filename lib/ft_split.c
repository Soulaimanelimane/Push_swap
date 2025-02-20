/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/30 19:38:23 by slimane           #+#    #+#             */
/*   Updated: 2025/02/10 22:36:07 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_count_word(char *str, char sep)
{
	int	i;
	int	len;

	len = 0;
	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		while (str[i] && str[i] == sep)
			i++;
		if (str[i])
			len++;
		while (str[i] && !(str[i] == sep))
			i++;
	}
	return (len);
}

static int	ft_len_to_sep(char *str, char sep)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != sep)
		i++;
	return (i);
}

static void	*ft_free(char **strs, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(strs[i]);
		i++;
	}
	free(strs);
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**strings;
	int		j;
	int		i;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	strings = malloc((ft_count_word((char *)s, c) + 1) * sizeof(char *));
	if (!strings)
		return (NULL);
	while (s[j])
	{
		while (s[j] == c)
			j++;
		if (s[j])
		{
			strings[i] = ft_substr(&s[j], 0, ft_len_to_sep((char *)&s[j], c));
			if (!strings[i++])
				return (ft_free(strings, i));
		}
		while (s[j] && (s[j] != c))
			j++;
	}
	return (strings[i] = NULL, strings);
}
