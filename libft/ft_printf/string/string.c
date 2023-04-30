/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:10 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:15 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

static int	string_len(const char *s);

void	string_main(int *count, va_list ap)
{
	char	*s;
	int		str_len;

	s = va_arg(ap, char *);
	str_len = string_len(s);
	(*count) += str_len;
	if (s == NULL)
	{
		write(1, "(null)", 6);
		return ;
	}
	while (*s)
	{
		write(1, s, 1);
		s++;
	}
}

static int	string_len(const char *s)
{
	int	count;

	count = 0;
	if (s == NULL)
		return (6);
	while (s[count])
		count++;
	return (count);
}
