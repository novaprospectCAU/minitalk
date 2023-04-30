/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   int_write_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:21 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:41 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "int_write_bonus.h"

static void	int_node_init(t_type *node, int *full_size, int *flag, int size);
static void	int_write2(t_type *node, int size, int *flag, int *full_size);
static void	int_write3(t_type *node, int *flag, int *full_size);
static void	int_write4(int *flag, char *arr, int plus);

void	int_write(int *count, t_type *node, char *arr, int size)
{
	int	flag[4];
	int	full_size;

	int_node_init(node, &full_size, flag, size);
	flag[0] = (arr[0] == '-');
	full_size += flag[0];
	int_write2(node, size, flag, &full_size);
	int_write3(node, flag, &full_size);
	(*count) += full_size;
	int_write4(flag, arr, node -> plus);
}

static void	int_node_init(t_type *node, int *full_size, int *flag, int size)
{
	*full_size = size;
	if (node -> plus == 1)
		node -> blank = 0;
	if (node -> minus > 0)
		node -> zero = 0;
	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
}

static void	int_write2(t_type *node, int size, int *flag, int *full_size)
{
	if (node -> plus == 1 && flag[0] == 0)
	{
		node -> blank = 0;
		(*full_size)++;
	}
	if (flag[0] == 0 && node -> blank == 1)
	{
		flag[1]++;
		(*full_size)++;
	}
	if (node -> precision > size)
	{
		flag[2] += (node -> precision - size);
		(*full_size) += (node -> precision - size);
	}
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
}

static void	int_write3(t_type *node, int *flag, int *full_size)
{
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

static void	int_write4(int *flag, char *arr, int plus)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	if (plus == 1 && flag[0] == 0)
		write(1, "+", 1);
	else if (flag[0] == 1)
		write(1, "-", 1);
	while (flag[2]-- > 0)
		write(1, "0", 1);
	arr++;
	while (*arr)
	{
		write(1, arr, 1);
		arr++;
	}
	while (flag[3]-- > 0)
		write(1, " ", 1);
}
