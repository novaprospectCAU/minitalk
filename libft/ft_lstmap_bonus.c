/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:21 by byelee            #+#    #+#             */
/*   Updated: 2022/11/15 14:26:33 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*fs_clear_all(t_list *move, t_list *start, void (*del)(void *))
{
	t_list	*tmp;

	tmp = start;
	while (start != move)
	{
		tmp = start -> next;
		if (tmp == move)
			tmp = NULL;
		ft_lstdelone(start, del);
		start = tmp;
	}
	return (NULL);
}

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*output;
	t_list	*start_node;

	if (lst == NULL)
		return (NULL);
	output = malloc(sizeof(t_list));
	if (output == NULL)
		return (NULL);
	output -> content = f(lst -> content);
	output -> next = lst -> next;
	start_node = output;
	while (lst -> next != NULL)
	{
		output -> next = (t_list *)malloc(sizeof(t_list));
		if (output -> next == NULL)
			return (fs_clear_all(output -> next, start_node, del));
		(output -> next)-> content = f((lst -> next)-> content);
		(output -> next)-> next = (lst -> next)-> next;
		output = (*(&output))-> next;
		lst = lst -> next;
	}
	return (start_node);
}
