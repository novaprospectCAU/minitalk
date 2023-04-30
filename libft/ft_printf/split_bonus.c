/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:19 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:45:20 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "split_bonus.h"
#include "node_bonus/node_bonus.h"
#include "node_bonus/fill_node_bonus.h"
#include "print_bonus.h"

static void	if_error(int *count, t_type *head);
static int	if_percent(const char *s, int *i, t_type *node);
static int	if_first_percent(const char *s, int *i, t_type *node);
static int	if_first_other(const char *s, int *i, t_type *node);

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

	check_err = 0;
	if (s[*i] == '%')
	{
		(*i)++;
		check_err = if_first_percent(s, i, node);
	}
	else
		check_err = if_first_other(s, i, node);
	return (check_err);
}

static int	if_first_percent(const char *s, int *i, t_type *node)
{
	fill_node(node, s, i);
	while ((s[*i] >= '0' && s[*i] <= '9') || s[*i] == ' ' || s[*i] == '#' \
			|| s[*i] == '+' || s[*i] == '-' || s[*i] == '.')
	{
		(*i)++;
		(node -> get_num)++;
	}
	(node -> get_num)++;
	if (s[*i] != '%' && s[*i] != 'i' && s[*i] != 'd' && s[*i] != 'u' && \
			s[*i] != 'x' && s[*i] != 'X' && s[*i] != 'c' && s[*i] != 's' && \
			s[*i] != 'p')
		return (0);
	else
	{
		node -> type = s[*i];
		(node -> get_num)++;
		(*i)++;
	}
	return (1);
}

static int	if_first_other(const char *s, int *i, t_type *node)
{
	while (s[*i] && s[*i] != '%')
	{
		(node -> get_num)++;
		(*i)++;
	}
	return (1);
}
