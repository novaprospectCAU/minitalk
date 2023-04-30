/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:30 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:32 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_H
# define CHAR_H

# ifndef STDARG_H
#  define STDARG_H
#  include <stdarg.h>
# endif

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

void	char_main(int *count, va_list ap);

#endif
