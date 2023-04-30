/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:20 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:22 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDR_H
# define ADDR_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

void	addr_main(int *count, va_list ap);

#endif
