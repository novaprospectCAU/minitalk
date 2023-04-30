/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:06 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:52 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*fs_find(const char *haystack, const char *needle, size_t len)
{
	size_t		len_haystack;
	size_t		len_needle;
	size_t		nd_idx;
	size_t		hs_idx;

	len_haystack = ft_strlen(haystack);
	len_needle = ft_strlen(needle);
	hs_idx = 0;
	while (hs_idx < len_haystack)
	{
		if (*(haystack + hs_idx) == *needle)
		{
			nd_idx = 0;
			while (nd_idx < len_needle && *(haystack + hs_idx + nd_idx))
			{
				if (*(haystack + hs_idx + nd_idx) != *(needle + nd_idx))
					break ;
				if (nd_idx + 1 == len_needle && len > hs_idx + nd_idx)
					return ((char *)(haystack + hs_idx));
				nd_idx++;
			}
		}
		hs_idx++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*output;

	if (*needle == '\0')
		return ((char *)haystack);
	output = fs_find(haystack, needle, len);
	return (output);
}
