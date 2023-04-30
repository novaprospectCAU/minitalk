/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:37:09 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:37:26 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILL_NODE_BONUS_H
# define FILL_NODE_BONUS_H

# include "../type_bonus.h"

void	fill_node2(t_type *node, const char *s, int *i, int *x);
void	fill_zero(t_type *node, const char *s, int *i, int *x);
void	fill_width(t_type *node, const char *s, int *i, int *x);
void	fill_minus(t_type *node, const char *s, int *i, int *x);
void	fill_precision(t_type *node, const char *s, int *i, int *x);

#endif
