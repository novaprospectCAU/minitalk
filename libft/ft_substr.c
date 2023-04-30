/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:10 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:54 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char const	*ps;
	char		*output;
	size_t		len_new;
	size_t		len_out;

	if (start > ft_strlen(s))
		return (ft_strdup(""));
	ps = s + start;
	len_new = ft_strlen(ps);
	if (len > len_new)
		output = malloc(len_new + 1);
	else
		output = malloc(len + 1);
	if (output == NULL)
		return (NULL);
	len_out = 0;
	while (*ps && len-- > 0)
	{
		*output++ = *ps++;
		len_out++;
	}
	*output = '\0';
	output -= len_out;
	return (output);
}
