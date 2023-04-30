/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:46 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:44 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	index;
	size_t	len;

	len = ft_strlen(s);
	index = 0;
	while (index <= len)
	{
		if (*(s + index) == (char)c)
			return ((char *)(s + index));
		index++;
	}
	return (NULL);
}
