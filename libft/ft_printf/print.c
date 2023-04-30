/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:45:36 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:45:39 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print.h"
#include "addr/addr.h"
#include "char/char.h"
#include "hex/hex.h"
#include "int/int.h"
#include "string/string.h"
#include "uint/uint.h"

static void	print_string(const char *s, int *count, int *start);
static void	percent_main(int *count, int *num);
static void	control_main(int *count, t_type *p, va_list ap);

void	print_all(const char *s, int *count, t_type *head, va_list ap)
{
	t_type	*p;
	int		num;

	p = head;
	num = 0;
	while (p != NULL)
	{
		if (p -> type == '~')
			print_string(s, count, &num);
		else if (p -> type == '%')
			percent_main(count, &num);
		else
		{
			control_main(count, p, ap);
			num += 2;
		}
		p = p -> next;
	}
}

static void	control_main(int *count, t_type *p, va_list ap)
{
	if (p -> type == 'c')
		char_main(count, ap);
	else if (p -> type == 's')
		string_main(count, ap);
	else if (p -> type == 'd' || p -> type == 'i')
		int_main(count, ap);
	else if (p -> type == 'p')
		addr_main(count, ap);
	else if (p -> type == 'x' || p -> type == 'X')
		hex_main(count, p, ap);
	else if (p -> type == 'u')
		uint_main(count, ap);
}

static void	print_string(const char *s, int *count, int *start)
{
	int	i;

	i = 0;
	while (s[*start + i] && s[*start + i] != '%')
	{
		write(1, &s[*start + i], 1);
		i++;
		(*count)++;
	}
	*start += i;
}

static void	percent_main(int *count, int *num)
{
	write(1, "%%", 1);
	(*count)++;
	(*num) += 2;
}
