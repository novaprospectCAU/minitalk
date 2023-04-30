/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_bonus.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:20 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:39 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_bonus.h"
#include "int_write_bonus.h"

static int	int_arr_fill_special(char *arr, int input);
static int	int_arr_fill_neg(char *arr, int input);
static int	int_arr_fill_pos(char *arr, int input);
static void	int_arr_fill(char *arr, int input, int *radix);

void	int_main(int *count, t_type *node, va_list ap)
{
	char	arr[12];
	int		size;
	int		input;
	int		i;

	i = 0;
	size = 0;
	input = va_arg(ap, int);
	while (i < 12)
		arr[i++] = '\0';
	int_arr_fill(arr, input, &size);
	if (node -> precision == 0 && arr[1] == '0' && arr[2] == '\0')
	{
		arr[1] = '\0';
		size = 0;
	}
	int_write(count, node, arr, size);
}

static void	int_arr_fill(char *arr, int input, int *radix)
{
	if (input == -2147483648 || input == 0)
		*radix = int_arr_fill_special(arr, input);
	else if (input < 0)
		*radix = int_arr_fill_neg(arr, input);
	else
		*radix = int_arr_fill_pos(arr, input);
}

static int	int_arr_fill_special(char *arr, int input)
{
	if (input == 0)
	{
		arr[0] = ' ';
		arr[1] = '0';
		return (1);
	}
	else
	{
		arr[0] = '-';
		arr[1] = '2';
		arr[2] = '1';
		arr[3] = '4';
		arr[4] = '7';
		arr[5] = '4';
		arr[6] = '8';
		arr[7] = '3';
		arr[8] = '6';
		arr[9] = '4';
		arr[10] = '8';
		return (10);
	}
}

static int	int_arr_fill_neg(char *arr, int input)
{
	int		i;
	int		rev;
	char	temp;

	i = 1;
	rev = 1;
	arr[0] = '-';
	input *= -1;
	while (input > 0)
	{
		arr[i] = (char)(input % 10 + '0');
		input /= 10;
		i++;
	}
	while (rev <= ((i - 1) / 2))
	{
		temp = arr[rev];
		arr[rev] = arr[i - rev];
		arr[i - rev] = temp;
		rev++;
	}
	return (i - 1);
}

static int	int_arr_fill_pos(char *arr, int input)
{
	int		i;
	int		rev;
	char	temp;

	i = 1;
	rev = 1;
	arr[0] = ' ';
	while (input > 0)
	{
		arr[i] = (char)(input % 10 + '0');
		input /= 10;
		i++;
	}
	while (rev <= ((i - 1) / 2))
	{
		temp = arr[rev];
		arr[rev] = arr[i - rev];
		arr[i - rev] = temp;
		rev++;
	}
	return (i - 1);
}
