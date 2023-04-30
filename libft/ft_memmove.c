/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:30 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:36 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t count)
{
	if (dest == NULL && src == NULL)
		return (NULL);
	if ((char *)dest <= (char *)src)
		return (ft_memcpy(dest, src, count));
	else
	{
		dest += count;
		src += count;
		while (count--)
			*(char *)--dest = *(char *)--src;
	}
	return (dest);
}
