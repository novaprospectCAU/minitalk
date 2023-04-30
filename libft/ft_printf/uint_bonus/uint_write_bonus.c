/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   uint_write_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:30 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:32 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "uint_write_bonus.h"

static void	uint_write2(t_type *node, int *full_size, int *flag, int radix);
static void	uint_write3(char *arr, int *flag);

void	uint_write(int *count, t_type *node, int radix, char *arr)
{
	int	flag[4];
	int	full_size;

	full_size = radix;
	if (node -> minus > 0)
		node -> zero = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	uint_write2(node, &full_size, flag, radix);
	(*count) += full_size;
	uint_write3(arr, flag);
}

static void	uint_write2(t_type *node, int *full_size, int *flag, int radix)
{
	if (node -> precision > radix)
	{
		flag[2] += (node -> precision - radix);
		*full_size += (node -> precision - radix);
	}
	if (node -> width > *full_size)
	{
		flag[1] += (node -> width - *full_size);
		*full_size += (node -> width - *full_size);
	}
	if (node -> minus > *full_size)
	{
		flag[3] += (node -> minus - *full_size);
		*full_size += (node -> minus - *full_size);
	}
	if (node -> zero > *full_size && node -> precision == -1)
	{
		flag[2] += (node -> zero - *full_size);
		*full_size += (node -> zero - *full_size);
	}
	else if (node -> zero > *full_size && node -> precision > -1)
	{
		flag[1] += (node -> zero - *full_size);
		*full_size += (node -> zero - *full_size);
	}
}

static void	uint_write3(char *arr, int *flag)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	while (flag[2]-- > 0)
		write(1, "0", 1);
	while (*arr)
	{
		write(1, arr, 1);
		arr++;
	}
	while (flag[3]-- > 0)
		write(1, " ", 1);
}
