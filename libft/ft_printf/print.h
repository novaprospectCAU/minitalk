/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:45:37 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:45:39 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_H
# define PRINT_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "type.h"

void	print_all(const char *s, int *count, t_type *head, va_list ap);

#endif
