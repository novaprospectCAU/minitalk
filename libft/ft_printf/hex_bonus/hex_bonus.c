/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:17 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:35 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex_bonus.h"
#include "hex_write_bonus.h"

static void	hex_main2(int *count, t_type *node, char *arr, int size);
static void	hex_main3(t_type *node, int *flag, int *full_size);
static int	int_to_hex(t_type *node, char *arr, unsigned int input);
static void	hex_reverse_arr(char *arr, int size);

void	hex_main(int *count, t_type *node, va_list ap)
{
	char			arr[11];
	unsigned int	input;
	int				size;
	int				i;

	i = 0;
	while (i < 11)
		arr[i++] = '\0';
	input = va_arg(ap, unsigned int);
	size = int_to_hex(node, arr, input);
	hex_main2(count, node, arr, size);
}

static void	hex_main2(int *count, t_type *node, char *arr, int size)
{
	int	flag[4];
	int	full_size;

	full_size = size;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	if (node -> sharp == 1 && size != 0 && arr[0] != '0')
	{
		flag[0] = 1;
		full_size += 2;
	}
	if (node -> precision > size)
	{
		flag[2] += (node -> precision - size);
		full_size += (node -> precision - size);
	}
	hex_main3(node, flag, &full_size);
	(*count) += full_size;
	hex_write(flag, arr, node -> type);
}

static void	hex_main3(t_type *node, int *flag, int *full_size)
{
	if (node -> width > *full_size)
	{
		flag[1] += (node -> width - *full_size);
		(*full_size) += (node -> width - *full_size);
	}
	if (node -> minus > *full_size)
	{
		flag[3] += (node -> minus - *full_size);
		(*full_size) += (node -> minus - *full_size);
	}
	if (node -> zero > *full_size && node -> precision == -1)
	{
		flag[2] += (node -> zero - *full_size);
		(*full_size) += (node -> zero - *full_size);
	}
	else if (node -> zero > *full_size && node -> precision > -1)
	{
		flag[1] += (node -> zero - *full_size);
		(*full_size) += (node -> zero - *full_size);
	}
}

static int	int_to_hex(t_type *node, char *arr, unsigned int input)
{
	int	i;

	i = 0;
	if (node -> precision == 0 && input == 0)
		return (0);
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
