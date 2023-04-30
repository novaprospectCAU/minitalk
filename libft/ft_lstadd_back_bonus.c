/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:09 by byelee            #+#    #+#             */
/*   Updated: 2022/11/15 14:26:28 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	**pp;

	pp = lst;
	if (*(pp) == NULL)
	{
		*(pp) = new;
		return ;
	}
	while (*(pp) != NULL)
	{
		if ((*pp)-> next == NULL)
		{
			(*pp)-> next = new;
			break ;
		}
		pp = &(*pp)-> next;
	}
}
