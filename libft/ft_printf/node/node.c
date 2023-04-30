/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:00 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:03 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "node.h"

t_type	*new_node(t_type *prev)
{
	t_type	*node;

	node = malloc(sizeof(t_type));
	if (node == NULL)
		return (NULL);
	if (prev != NULL)
		prev -> next = node;
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
