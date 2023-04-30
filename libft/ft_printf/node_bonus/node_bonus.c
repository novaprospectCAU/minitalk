/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:24 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:42 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node_bonus.h"
#include "fill_node_bonus.h"

t_type	*new_node(t_type *prev)
{
	t_type	*node;

	node = malloc(sizeof(t_type));
	if (node == NULL)
		return (NULL);
	if (prev != NULL)
		prev -> next = node;
	node -> width = 0;
	node -> blank = 0;
	node -> zero = 0;
	node -> plus = 0;
	node -> minus = 0;
	node -> sharp = 0;
	node -> precision = -1;
	node -> get_num = 0;
	node -> type = '~';
	node -> next = NULL;
	return (node);
}

void	delete_all_node(t_type *head)
{
	t_type	*p;

	while (head != NULL)
	{
		p = head -> next;
		free(head);
		head = p;
	}
	head = NULL;
}

void	fill_node(t_type *node, const char *s, int *i)
{
	int	x;

	x = 0;
	while ((s[*i + x] >= '0' && s[*i + x] <= '9') || s[*i + x] == ' ' || \
	s[*i + x] == '#' || s[*i + x] == '+' || s[*i + x] == '-' \
	|| s[*i + x] == '.')
	{
		fill_node2(node, s, i, &x);
		if (s[*i + x] == '0')
			fill_zero(node, s, i, &x);
		else if (s[*i + x] > '0' && s[*i + x] <= '9')
			fill_width(node, s, i, &x);
		else if (s[*i + x] == '-')
			fill_minus(node, s, i, &x);
		if (s[*i + x] == '.')
			fill_precision(node, s, i, &x);
	}
}
