/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:39 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:42 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex.h"

static int	int_to_hex(t_type *node, char *arr, unsigned int input);
static void	hex_reverse_arr(char *arr, int size);

void	hex_main(int *count, t_type *node, va_list ap)
{
	char			arr[11];
	unsigned int	input;
	int				i;

	i = 0;
	while (i < 11)
		arr[i++] = '\0';
	i = 0;
	input = va_arg(ap, unsigned int);
	(*count) += int_to_hex(node, arr, input);
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
}

static int	int_to_hex(t_type *node, char *arr, unsigned int input)
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
			arr[i++] = (char)(input % 16 + '0');
		else
		{
			if (node -> type == 'x')
				arr[i++] = (char)(input % 16 + 'a' - 10);
			else
				arr[i++] = (char)(input % 16 + 'A' - 10);
		}
		input >>= 4;
	}
	hex_reverse_arr(arr, i);
	return (i);
}

static void	hex_reverse_arr(char *arr, int size)
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
