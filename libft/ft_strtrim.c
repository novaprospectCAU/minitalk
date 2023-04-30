/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:31:09 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:54 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fs_front(char const *s1, char const *set)
{
	int	idx;
	int	set_idx;

	idx = 0;
	while (s1[idx])
	{
		set_idx = 0;
		while (set[set_idx])
		{
			if (set[set_idx] == s1[idx])
				break ;
			set_idx++;
		}
		if (!set[set_idx])
			return (idx);
		idx++;
	}
	return (idx);
}

static int	fs_back(char const *s1, char const *set)
{
	int	idx;
	int	set_idx;

	idx = 0;
	while (s1[idx])
		idx++;
	idx--;
	while (s1[idx])
	{
		set_idx = 0;
		while (set[set_idx])
		{
			if (set[set_idx] == s1[idx])
				break ;
			set_idx++;
		}
		if (!set[set_idx] || idx == 0)
			return (idx);
		idx--;
	}
	return (idx);
}

static char	*fs_strtrim(char const *s1, int fidx, int bidx)
{
	char	*output;
	int		idx;

	if (fidx == bidx)
	{
		output = malloc(2);
		if (output == NULL)
			return (NULL);
		output[0] = s1[fidx];
		output[1] = '\0';
		return (output);
	}
	output = malloc(bidx - fidx + 2);
	if (output == NULL)
		return (NULL);
	idx = 0;
	while (fidx <= bidx)
	{
		output[idx] = s1[fidx++];
		idx++;
	}		
	output[idx] = '\0';
	return (output);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*output;
	int		front;
	int		back;

	front = fs_front(s1, set);
	back = fs_back(s1, set);
	if (ft_strlen(s1) == 0 || back == 0)
	{
		output = malloc (1);
		if (output == NULL)
			return (NULL);
		*output = '\0';
		return (output);
	}
	if (front <= back)
		return (fs_strtrim(s1, front, back));
	return (NULL);
}
