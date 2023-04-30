/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:45:15 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:45:19 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split.h"
#include "node/node.h"
#include "print.h"

static void	if_error(int *count, t_type *head);
static int	if_percent(const char *s, int *i, t_type *node);
static int	if_first_percent(const char *s, int *i, t_type *node);
static int	if_first_other(const char *s, int *i);

void	split_main(const char *s, va_list ap, int *count)
{
	int		i;
	t_type	*prev;
	t_type	*node;
	t_type	*head;

	i = 0;
	node = new_node(NULL);
	if (node == NULL)
	{
		*count = -1;
		return ;
	}
	head = node;
	while (s[i])
	{
		prev = node;
		node -> next = new_node(prev);
		if (node -> next == NULL || \
		if_percent(s, &i, node -> next) == 0)
			return (if_error(count, head));
		node = node -> next;
	}
	print_all(s, count, head -> next, ap);
	delete_all_node(head);
}

static void	if_error(int *count, t_type *head)
{
	delete_all_node(head);
	*count = -1;
}

static int	if_percent(const char *s, int *i, t_type *node)
{
	int	check_err;

	if (s[*i] == '%')
	{
		(*i)++;
		check_err = if_first_percent(s, i, node);
	}
	else
		check_err = if_first_other(s, i);
	return (check_err);
}

static int	if_first_percent(const char *s, int *i, t_type *node)
{
	if (s[*i] != '%' && s[*i] != 'i' && s[*i] != 'd' && s[*i] != 'u' && \
			s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'c' && s[*i] != 's' && \
			s[*i] != 'p')
		return (0);
	else
	{
		node -> type = s[*i];
		(*i)++;
	}
	return (1);
}

static int	if_first_other(const char *s, int *i)
{
	while (s[*i] && s[*i] != '%')
		(*i)++;
	return (1);
}
