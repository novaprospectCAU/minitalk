/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 14:26:24 by byelee            #+#    #+#             */
/*   Updated: 2022/11/15 14:26:45 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		count;
	t_list	*p;

	p = lst;
	count = 0;
	if (!p)
		return (0);
	while (p != NULL)
	{
		count++;
		p = p -> next;
	}
	return (count);
}
