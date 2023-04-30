/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:49 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:44 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	char	*result;

	len = ft_strlen(s1);
	result = malloc(len + 1);
	if (result == NULL)
		return (NULL);
	while (*s1)
		*result++ = *s1++;
	*result = '\0';
	return (result - len);
}
