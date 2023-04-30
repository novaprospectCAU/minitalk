/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:28 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:44 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uint_bonus.h"
#include "uint_write_bonus.h"

static int	uint_len(t_type *node, unsigned int input);
static void	uint_fill_arr(t_type *node, char *arr, unsigned int input);
static void	uint_fill_arr2(char *arr, int i);

void	uint_main(int *count, t_type *node, va_list ap)
{
	int		input;
	int		radix;
	char	arr[11];

	input = va_arg(ap, unsigned int);
	radix = uint_len(node, input);
	uint_fill_arr(node, arr, input);
	uint_write(count, node, radix, arr);
}

static int	uint_len(t_type *node, unsigned int input)
{
	int	radix;

	radix = 0;
	if (input == 0 && node -> precision == 0)
		return (0);
	else if (input == 0)
		return (1);
	while (input > 0)
	{
		radix++;
		input /= 10;
	}
	return (radix);
}

static void	uint_fill_arr(t_type *node, char *arr, unsigned int input)
{
	int	i;

	i = 0;
	while (i < 11)
		arr[i++] = '\0';
	i = 0;
	if (input == 0 && node -> precision == 0)
		return ;
	else if (input == 0)
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
