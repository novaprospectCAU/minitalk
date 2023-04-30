/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:45:17 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:45:26 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "print_bonus.h"
#include "addr_bonus/addr_bonus.h"
#include "char_bonus/char_bonus.h"
#include "hex_bonus/hex_bonus.h"
#include "int_bonus/int_bonus.h"
#include "uint_bonus/uint_bonus.h"
#include "string_bonus/string_bonus.h"

static void	print_string(const char *s, int *count, int *start, t_type *node);
static void	percent_main(int *count, int *num, t_type *node);
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
		{
			print_string(s, count, &num, p);
			p = p -> next;
			continue ;
		}
		else if (p -> type == '%')
		{
			percent_main(count, &num, p);
			p = p -> next;
			continue ;
		}
		else
			control_main(count, p, ap);
		num += p -> get_num;
		p = p -> next;
	}
}

static void	control_main(int *count, t_type *p, va_list ap)
{
	if (p -> type == 'c')
		char_main(count, p, ap);
	else if (p -> type == 's')
		string_main(count, p, ap);
	else if (p -> type == 'd' || p -> type == 'i')
		int_main(count, p, ap);
	else if (p -> type == 'p')
		addr_main(count, p, ap);
	else if (p -> type == 'x' || p -> type == 'X')
		hex_main(count, p, ap);
	else if (p -> type == 'u')
		uint_main(count, p, ap);
}

static void	print_string(const char *s, int *count, int *start, t_type *node)
{
	int	size;

	size = node -> get_num;
	write(1, s + *start, size);
	*start += size;
	*count += size;
}

static void	percent_main(int *count, int *num, t_type *node)
{
	int	i;

	if (node -> minus > 0)
	{
		i = node -> minus - 1;
		(*count) += (i + 1);
		write(1, "%%", 1);
		while (i-- > 0)
			write(1, " ", 1);
	}
	else if (node -> width > 0)
	{
		i = node -> width - 1;
		(*count) += (i + 1);
		while (i-- > 0)
			write(1, " ", 1);
		write(1, "%%", 1);
	}
	else
	{
		write(1, "%%", 1);
		(*count)++;
	}
	(*num) += 2;
}
