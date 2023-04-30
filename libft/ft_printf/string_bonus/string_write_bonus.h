/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_write_bonus.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:12 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:30 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRING_WRITE_BONUS_H
# define STRING_WRITE_BONUS_H

# ifndef UNISTD_H
#  define UNISTD_H
#  include <unistd.h>
# endif

# include "../type_bonus.h"

void	string_write(int *count, t_type *node, char *s, int len);

#endif
