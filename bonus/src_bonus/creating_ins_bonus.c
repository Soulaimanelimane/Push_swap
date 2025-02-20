/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creating_ins_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/27 17:33:45 by slimane           #+#    #+#             */
/*   Updated: 2025/02/13 10:25:52 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

t_checker	*new_node_ins(char *str)
{
	t_checker	*new;

	new = malloc(sizeof(t_checker));
	if (!new)
		return (NULL);
	new->data = str;
	new->next = NULL;
	return (new);
}

void	add_back_ins(t_checker **stack, t_checker *new)
{
	t_checker	*last;

	if (!new || !stack)
		return ;
	if (!*stack)
	{
		*stack = new;
		return ;
	}
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = new;
}

int	check_ins(char *str)
{
	if (ft_strcmp(str, "sa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "sb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pa\n") == 0)
		return (1);
	else if (ft_strcmp(str, "pb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rra\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrb\n") == 0)
		return (1);
	else if (ft_strcmp(str, "ss\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rr\n") == 0)
		return (1);
	else if (ft_strcmp(str, "rrr\n") == 0)
		return (1);
	else
		return (0);
}

t_checker	*creating_instraction(void)
{
	char		*line;
	t_checker	*checker;
	t_checker	*ins;

	line = get_next_line(0);
	checker = new_node_ins(line);
	if (!checker)
		return (free(line), NULL);
	while (line != NULL)
	{
		if (check_ins(line) == 0)
		{
			write(2, "Error\n", 6);
			ft_clear(&checker);
			get_next_line(4);
			return (NULL);
		}
		line = get_next_line(0);
		ins = new_node_ins(line);
		if (!ins)
			return (ft_clear(&checker), free(line), NULL);
		add_back_ins(&checker, ins);
	}
	return (checker);
}
