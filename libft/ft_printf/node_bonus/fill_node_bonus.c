/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_node_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:22 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:42 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fill_node_bonus.h"

void	fill_node2(t_type *node, const char *s, int *i, int *x)
{
	if (s[*i + *x] == '+')
	{
		node -> plus = 1;
		(*x)++;
	}
	if (s[*i + *x] == '#')
	{
		node -> sharp = 1;
		(*x)++;
	}
	if (s[*i + *x] == ' ')
	{
		node -> blank = 1;
		(*x)++;
	}
}

void	fill_zero(t_type *node, const char *s, int *i, int *x)
{
	(*x)++;
	while ((s[*i + *x] >= '0' && s[*i + *x] <= '9') || s[*i + *x] == '+' \
	|| s[*i + *x] == '#' || s[*i + *x] == ' ')
	{
		if (s[*i + *x] == '+' || s[*i + *x] == '#' || s[*i + *x] == ' ')
		{
			fill_node2(node, s, i, x);
			continue ;
		}
		node -> zero *= 10;
		node -> zero += (int)(s[*i + *x] - '0');
		(*x)++;
	}
}

void	fill_width(t_type *node, const char *s, int *i, int *x)
{
	while ((s[*i + *x] >= '0' && s[*i + *x] <= '9') || s[*i + *x] == '+' \
	|| s[*i + *x] == '#' || s[*i + *x] == ' ')
	{
		if (s[*i + *x] == '+' || s[*i + *x] == '#' || s[*i + *x] == ' ')
		{
			fill_node2(node, s, i, x);
			continue ;
		}
		node -> width *= 10;
		node -> width += (int)(s[*i + *x] - '0');
		(*x)++;
	}
}

void	fill_minus(t_type *node, const char *s, int *i, int *x)
{
	(*x)++;
	while ((s[*i + *x] >= '0' && s[*i + *x] <= '9') || s[*i + *x] == '+' \
	|| s[*i + *x] == '#' || s[*i + *x] == ' ')
	{
		if (s[*i + *x] == '+' || s[*i + *x] == '#' || s[*i + *x] == ' ')
		{
			fill_node2(node, s, i, x);
			continue ;
		}
		node -> minus *= 10;
		node -> minus += (int)(s[*i + *x] - '0');
		(*x)++;
	}
}

void	fill_precision(t_type *node, const char *s, int *i, int *x)
{
	node -> precision = 0;
	(*x)++;
	while ((s[*i + *x] >= '0' && s[*i + *x] <= '9') || s[*i + *x] == '+' \
	|| s[*i + *x] == '#' || s[*i + *x] == ' ')
	{
		if (s[*i + *x] == '+' || s[*i + *x] == '#' || s[*i + *x] == ' ')
		{
			fill_node2(node, s, i, x);
			continue ;
		}
		node -> precision *= 10;
		node -> precision += (int)(s[*i + *x] - '0');
		(*x)++;
	}
}
