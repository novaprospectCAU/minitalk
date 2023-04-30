/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:03 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:50 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	index;
	char			*result;

	result = malloc(ft_strlen(s) + 1);
	if (result == NULL)
		return (NULL);
	index = 0;
	while (*s)
	{
		*result = f(index, *s);
		s++;
		result++;
		index++;
	}
	*result = '\0';
	result -= index;
	return (result);
}
