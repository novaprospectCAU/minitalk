/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:14 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:45:21 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_BONUS_H
# define PRINT_BONUS_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "type_bonus.h"

void	print_all(const char *s, int *count, t_type *head, va_list ap);

#endif