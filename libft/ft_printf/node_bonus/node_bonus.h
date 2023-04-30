/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:10 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:29 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_BONUS_H
# define NODE_BONUS_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# include "../type_bonus.h"

t_type	*new_node(t_type *prev);
void	delete_all_node(t_type *head);
void	fill_node(t_type *node, const char *s, int *i);

#endif
