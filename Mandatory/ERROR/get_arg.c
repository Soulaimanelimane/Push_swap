/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_arg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:18:49 by slimane           #+#    #+#             */
/*   Updated: 2025/02/13 11:13:49 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "error.h"

void	ft_free_split(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

int	*get_array(char **strs, int *arr, int *j)
{
	int	len;
	int	check;

	len = 0;
	check = 0;
	while (strs[len])
	{
		arr[*j] = ft_atoi(strs[len], &check);
		if (check == 1)
			return (free(arr), ft_free_split(strs), NULL);
		(*j)++;
		len++;
	}
	ft_free_split(strs);
	return (arr);
}

int	ft_len_split(char **str)
{
	int	i;

	i = 0;
	while (str[i] != NULL)
		i++;
	return (i);
}

int	*get_arg(char **str, int *size)
{
	int		i;
	int		*arr;
	char	**strs;
	int		len;

	len = ft_len(str);
	if (len == -1)
		return (NULL);
	arr = malloc(len * sizeof(int));
	if (!arr)
		return (NULL);
	i = 1;
	while (str[i] != NULL)
	{
		strs = ft_split(str[i], ' ');
		if (!strs || ft_len_split(strs) == 0)
			return (free(arr), free(strs), NULL);
		arr = get_array(strs, arr, size);
		if (arr == NULL)
			return (NULL);
		i++;
	}
	if (check_arg(arr, *size) == -1)
		return (free(arr), NULL);
	return (arr);
}
