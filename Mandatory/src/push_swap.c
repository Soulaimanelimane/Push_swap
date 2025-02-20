/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/10 23:17:44 by slimane           #+#    #+#             */
/*   Updated: 2025/02/17 20:44:10 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **lst)
{
	if ((*lst)->index > (*lst)->next->index)
		swap(lst, SA);
}

void	ft_lstclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!(*lst))
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = NULL;
		*lst = tmp;
	}
	*lst = NULL;
}

void	handle_sorting(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i == 2)
		sort_two(stack_a);
	else if (i == 3)
		sort_three(stack_a);
	else if (i == 4)
		sort_four(stack_a, stack_b);
	else if (i == 5)
		sort_five(stack_a, stack_b);
	else
		big_sort(stack_a, stack_b, i);
	ft_lstclear(stack_a);
}

int	main(int ac, char **av)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;
	int		*numbers;

	stack_a = NULL;
	stack_b = NULL;
	if (ac == 1)
		return (1);
	i = 0;
	numbers = get_arg(av, &i);
	if (numbers == NULL)
		return (write(2, "Error\n", 6), 1);
	stack_a = creating_for_tr(numbers, i);
	if (!stack_a)
		return (free(numbers), 1);
	ft_index(&stack_a);
	if (is_sorted(stack_a))
	{
		free(numbers);
		ft_lstclear(&stack_a);
		return (0);
	}
	handle_sorting(&stack_a, &stack_b, i);
	free(numbers);
}
