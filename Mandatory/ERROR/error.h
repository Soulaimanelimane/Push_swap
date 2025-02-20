/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: slimane <slimane@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 00:28:52 by slimane           #+#    #+#             */
/*   Updated: 2025/02/17 20:35:04 by slimane          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

# include <stdlib.h>
# include "../../lib/libft.h"

int		*get_arg(char **str, int *len);
int		ft_len(char **str);
int		check_arg(int *lst, int nb);
int		ft_count_word(char *str, char sep);

#endif