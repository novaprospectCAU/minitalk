/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:06 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:24 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_BONUS_H
# define INT_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "../type_bonus.h"

void	int_main(int *count, t_type *node, va_list ap);

#endif
