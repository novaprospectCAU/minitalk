/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:19 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:23 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addr.h"

static int	addr_to_hex(unsigned long long int input, char *arr);
static void	addr_reverse_arr(char *arr, int size);

void	addr_main(int *count, va_list ap)
{
	unsigned long long int	input;
	char					addr[30];
	int						i;

	i = 0;
	input = (unsigned long long int)va_arg(ap, void *);
	while (i < 30)
		addr[i++] = '\0';
	i = 0;
	(*count) += addr_to_hex(input, addr);
	write(1, "0x", 2);
	while (addr[i])
	{
		write(1, &addr[i], 1);
		i++;
	}
	(*count) += 2;
}

static int	addr_to_hex(unsigned long long int input, char *arr)
{
	int	i;

	i = 0;
	if (input == 0)
	{
		arr[0] = '0';
		return (1);
	}
	while (input > 0)
	{
		if (input % 16 < 10)
			arr[i] = (char)(input % 16 + '0');
		else
			arr[i] = (char)(input % 16 + 'a' - 10);
		i++;
		input /= 16;
	}
	addr_reverse_arr(arr, i);
	return (i);
}

static void	addr_reverse_arr(char *arr, int size)
{
	int		i;
	char	temp;

	i = 0;
	while (i <= ((size - 1) / 2))
	{
		temp = arr[i];
		arr[i] = arr[size - i - 1];
		arr[size - i - 1] = temp;
		i++;
	}
}
