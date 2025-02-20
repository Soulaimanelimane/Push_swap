/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:26:03 by slimane           #+#    #+#             */
/*   Updated: 2025/02/17 20:34:26 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include "../ERROR/error.h"
# include "../sort/sort.h"

t_stack	*creating_for_tr(int *numbers, int len);
void	ft_lstclear(t_stack **lst);
void	swap(t_stack **lst, int flag);
void	push(t_stack **stack_a, t_stack **stack_b, int flag);
void	rotate(t_stack **stack, int flag);
void	reverse(t_stack **stack, int flag);
void	ft_index(t_stack **stack);
int		is_sorted(t_stack *stack);
int		ft_lstsize_lib(t_stack *lst);

# define SA 1
# define SB 2
# define PA 1
# define PB 0
# define RA 1
# define RB 2
# define RRA 1
# define RRB 2

#endif
