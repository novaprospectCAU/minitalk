/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:10 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:33 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addr_bonus.h"
#include "addr_write_bonus.h"

static int	addr_to_hex(unsigned long long int input, char *arr);
static void	addr_reverse_arr(char *arr, int size);

void	addr_main(int *count, t_type *node, va_list ap)
{
	unsigned long long int	input;
	char					addr[30];
	int						size;
	int						i;

	i = 0;
	input = (unsigned long long int)va_arg(ap, void *);
	while (i < 30)
		addr[i++] = '\0';
	size = addr_to_hex(input, addr);
	addr_write(count, node, addr, size);
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
