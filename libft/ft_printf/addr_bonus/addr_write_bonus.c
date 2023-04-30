/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addr_write_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:13 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:33 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "addr_write_bonus.h"

static void	addr_write2(char *arr, int *flag);

void	addr_write(int *count, t_type *node, char *addr, int len)
{
	int	flag[4];
	int	full_size;

	full_size = len + 2;
	flag[1] = 0;
	flag[3] = 0;
	if (node -> minus > full_size)
		flag[3] = node -> minus - len - 2;
	else if (node -> width > full_size)
		flag[1] = node -> width - len - 2;
	full_size += (flag[1] + flag[3]);
	(*count) += full_size;
	addr_write2(addr, flag);
}

static void	addr_write2(char *arr, int *flag)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	write(1, "0x", 2);
	while (*arr)
	{
		write(1, arr, 1);
		arr++;
	}
	while (flag[3]-- > 0)
		write(1, " ", 1);
}
