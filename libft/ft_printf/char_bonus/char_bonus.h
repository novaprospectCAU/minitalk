/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:01 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:19 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_BONUS_H
# define CHAR_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "../type_bonus.h"

void	char_main(int *count, t_type *node, va_list ap);

#endif
