/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:15 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:45:24 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPLIT_BONUS_H
# define SPLIT_BONUS_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "type_bonus.h"

void	split_main(const char *s, va_list ap, int *count);

#endif
