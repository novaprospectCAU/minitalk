/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:11 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:30 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_BONUS_H
# define STRING_BONUS_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "../type_bonus.h"

void	string_main(int *count, t_type *node, va_list ap);

#endif
