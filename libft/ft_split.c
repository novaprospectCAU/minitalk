/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:44 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:42 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fs_clear_all(char **output, int count)
{
	int	i;

	i = 0;
	if (output[count] == NULL)
	{
		while (i < count)
		{
			free(output[i]);
			output[i] = NULL;
			i++;
		}
		free(output);
		output = NULL;
		return (0);
	}
	return (1);
}

static int	fs_count(const char *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	if (s[i] == '\0')
		return (1);
	while (s[i])
	{
		if (s[i] && s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count + 1);
}

static int	fs_len(const char *s, char c, int idx)
{
	int	len;

	len = 0;
	while (s[idx] && s[idx] != c)
	{
		len++;
		idx++;
	}
	return (len);
}

static void	fs_split(const char *s, int *s_idx, int len, char output[])
{
	int	len_idx;

	len_idx = 0;
	while (len_idx < len)
	{
		output[len_idx] = s[*s_idx];
		(*s_idx)++;
		len_idx++;
	}
	output[len_idx] = '\0';
}

char	**ft_split(const char *s, char c)
{
	char	**output;
	int		s_idx;
	int		count_idx;
	int		len;

	s_idx = 0;
	count_idx = 0;
	output = malloc(fs_count(s, c) * sizeof(char *));
	if (output == NULL)
		return (NULL);
	while (count_idx < fs_count(s, c) - 1)
	{
		while (s[s_idx] == c)
			s_idx++;
		len = fs_len(s, c, s_idx);
		output[count_idx] = malloc((len + 1) * sizeof(char));
		if (!fs_clear_all(output, count_idx))
			return (NULL);
		fs_split(s, &s_idx, len, output[count_idx]);
		count_idx++;
	}
	output[fs_count(s, c) - 1] = NULL;
	return (output);
}
