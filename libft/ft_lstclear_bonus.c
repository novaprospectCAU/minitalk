/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:12 by byelee            #+#    #+#             */
/*   Updated: 2022/11/15 14:26:30 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*p;
	t_list	*p_next;

	p = *lst;
	p_next = p;
	while (p != NULL)
	{
		del(p -> content);
		p_next = p -> next;
		free(p);
		p = p_next;
	}
	*lst = NULL;
}
