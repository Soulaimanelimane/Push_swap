/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_len_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:52:48 by slimane           #+#    #+#             */
/*   Updated: 2025/02/13 18:47:28 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error_bonus.h"

int	count_words_and_free(char *str, int *len)
{
	int		j;
	char	**strs;

	j = 0;
	strs = ft_split(str, ' ');
	if (strs == NULL)
		return (-1);
	while (strs[j])
	{
		(*len)++;
		free(strs[j]);
		j++;
	}
	free(strs);
	return (0);
}

int	ft_len(char **str)
{
	int	len;
	int	i;

	len = 0;
	i = 1;
	while (str[i] != NULL)
	{
		if (ft_count_word(str[i], ' ') > 1)
		{
			if (count_words_and_free(str[i], &len) == -1)
				return (-1);
		}
		else
			len++;
		i++;
	}
	return (len);
}
