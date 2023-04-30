/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_write_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:15 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:18 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UINT_WRITE_BONUS_H
# define UINT_WRITE_BONUS_H

# include <unistd.h>
# include "../type_bonus.h"

void	uint_write(int *count, t_type *node, int radix, char *arr);

#endif
