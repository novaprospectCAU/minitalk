/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_write_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:05 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:24 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEX_WRITE_BONUS_H
# define HEX_WRITE_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "../type_bonus.h"

void	hex_write(int *flag, char *arr, char type);

#endif
