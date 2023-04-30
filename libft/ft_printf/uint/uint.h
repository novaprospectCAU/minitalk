/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:22 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:23 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UINT_H
# define UINT_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

void	uint_main(int *count, va_list ap);

#endif
