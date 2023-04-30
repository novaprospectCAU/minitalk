/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:11 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:12 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_H
# define STRING_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# ifndef STDARG_H
#  include <stdarg.h>
#  define STDARG_H
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

void	string_main(int *count, va_list ap);

#endif
