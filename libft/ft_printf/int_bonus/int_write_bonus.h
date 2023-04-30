/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_write_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:07 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:25 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_WRITE_BONUS_H
# define INT_WRITE_BONUS_H

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "../type_bonus.h"

void	int_write(int *count, t_type *node, char *arr, int size);

#endif
