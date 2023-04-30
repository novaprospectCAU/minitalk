/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:25 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:43 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_bonus.h"
#include "string_write_bonus.h"

static int	string_len(char *s);
static void	string_fill(char *dst, char *src, int size);

void	string_main(int *count, t_type *node, va_list ap)
{
	char	*s;
	char	*new_str;
	int		str_len;

	s = va_arg(ap, char *);
	str_len = string_len(s);
	new_str = malloc(sizeof(char) * (str_len + 1));
	if (new_str == NULL)
	{
		(*count) = -1;
		return ;
	}
	string_fill(new_str, s, str_len);
	string_write(count, node, new_str, str_len);
	free(new_str);
}

static int	string_len(char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (6);
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

static void	string_fill(char *dst, char *src, int size)
{
	int	i;

	i = 0;
	if (src == NULL)
	{
		dst[0] = '(';
		dst[1] = 'n';
		dst[2] = 'u';
		dst[3] = 'l';
		dst[4] = 'l';
		dst[5] = ')';
		dst[6] = '\0';
		return ;
	}
	while (size-- > 0)
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}
