/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:47:20 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:47:23 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uint.h"

static int	uint_len(unsigned int input);
static void	uint_fill_arr(char *arr, unsigned int input);
static void	uint_fill_arr2(char *arr, int i);

void	uint_main(int *count, va_list ap)
{
	int		input;
	char	arr[11];
	int		i;

	i = 0;
	input = va_arg(ap, unsigned int);
	(*count) += uint_len(input);
	uint_fill_arr(arr, input);
	while (arr[i])
	{
		write(1, &arr[i], 1);
		i++;
	}
}

static int	uint_len(unsigned int input)
{
	int	radix;

	radix = 0;
	if (input == 0)
		return (1);
	while (input > 0)
	{
		radix++;
		input /= 10;
	}
	return (radix);
}

static void	uint_fill_arr(char *arr, unsigned int input)
{
	int	i;

	i = 0;
	while (i < 11)
		arr[i++] = '\0';
	i = 0;
	if (input == 0)
	{
		arr[0] = '0';
		return ;
	}
	while (input > 0)
	{
		arr[i++] = (char)(input % 10 + '0');
		input /= 10;
	}
	uint_fill_arr2(arr, i);
}

static void	uint_fill_arr2(char *arr, int i)
{
	int		rev;
	char	temp;

	rev = 0;
	while (rev <= ((i - 1) / 2))
	{
		temp = arr[rev];
		arr[rev] = arr[i - rev - 1];
		arr[i - rev - 1] = temp;
		rev++;
	}
}
