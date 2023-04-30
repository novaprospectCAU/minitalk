/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_bonus.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:04 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:20 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_BONUS_H
# define HEX_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# include "../type_bonus.h"

void	hex_main(int *count, t_type *node, va_list ap);

#endif
