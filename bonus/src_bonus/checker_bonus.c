/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:17:44 by slimane           #+#    #+#             */
/*   Updated: 2025/02/19 11:40:03 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

void	ft_clear(t_checker **list)
{
	t_checker	*tmp;
	t_checker	*current;

	current = *list;
	if (!*list)
		return ;
	while (current)
	{
		tmp = current->next;
		free(current->data);
		free(current);
		current = tmp;
	}
	list = NULL;
}
void f (){system("leaks checker");}
int	main(int ac, char **av)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_checker	*list;
	int			i;
	int			*numbers;

	atexit(f);
	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (0);
	i = 0;
	numbers = get_arg(av, &i);
	if (numbers == NULL)
		return (write(2, "Error\n", 6), 1);
	stack_a = creating_for_tr(numbers, i);
	if (!stack_a)
		return (free(numbers), 1);
	(ft_index(&stack_a), list = creating_instraction());
	if (list == NULL)
		return (ft_lstclear(&stack_a), ft_lstclear(&stack_b), free(numbers), 1);
	if (ft_cheker(&stack_a, &stack_b, &list) && is_sorted(stack_a, stack_b))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	(free(numbers), ft_clear(&list));
}
