/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:08 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:53 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*p;

	len = ft_strlen(s);
	p = (char *)s + len;
	len++;
	while (len-- > 0)
	{
		if (*p == (char)c)
			return (p);
		p--;
	}
	return (NULL);
}
