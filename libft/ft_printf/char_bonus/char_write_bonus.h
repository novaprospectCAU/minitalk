/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_write_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:02 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:20 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHAR_WRITE_BONUS_H
# define CHAR_WRITE_BONUS_H

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "../type_bonus.h"

void	char_write(int *count, t_type *node, unsigned char c);

#endif
