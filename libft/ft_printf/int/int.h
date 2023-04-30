/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:49 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:51 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INT_H
# define INT_H

# ifndef STDARG_H
#  include <stdarg.h>
#  define STDARG_H
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

void	int_main(int *count, va_list ap);

#endif
