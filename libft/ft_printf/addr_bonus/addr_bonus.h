/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:57 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:18 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDR_BONUS_H
# define ADDR_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "../type_bonus.h"

void	addr_main(int *count, t_type *node, va_list ap);

#endif
