/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_write_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:00 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:19 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDR_WRITE_BONUS_H
# define ADDR_WRITE_BONUS_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "../type_bonus.h"

void	addr_write(int *count, t_type *node, char *addr, int len);

#endif