/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:01 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:03 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_H
# define NODE_H

# ifndef STDLIB_H
#  define STDLIB_H
#  include <stdlib.h>
# endif

# include "../type.h"

t_type	*new_node(t_type *prev);
void	delete_all_node(t_type *head);

#endif