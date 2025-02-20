/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:26:03 by slimane           #+#    #+#             */
/*   Updated: 2025/02/17 20:36:27 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_BONUS_H
# define CHECKER_BONUS_H

# include <stdlib.h>
# include "../ERROR_bonus/error_bonus.h"

typedef struct checker
{
	char			*data;
	struct checker	*next;
}	t_checker;

int			ft_cheker(t_stack **stack_a, t_stack **stack_b, t_checker **list);
t_stack		*creating_for_tr(int *numbers, int len);
t_checker	*creating_instraction(void);
void		swap(t_stack **lst);
void		push(t_stack **stack_a, t_stack **stack_b, int flag);
void		rotate(t_stack **stack);
void		reverse(t_stack **stack);
void		ft_index(t_stack **stack);
int			is_sorted(t_stack *stack, t_stack *stack_b);
void		group_ins_2(t_stack **stack_a, t_stack **stack_b, int flag);
void		ft_lstclear(t_stack **lst);
void		ft_clear(t_checker **list);
int			ft_lstsize_lib(t_stack *lst);

# define PA 1
# define PB 0
# define RR 0
# define RRR 1
# define SS 2

#endif 