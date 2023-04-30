/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hex_write_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:18 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:38 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hex_write_bonus.h"

void	hex_write(int *flag, char *arr, char type)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	if (flag[0] == 1 && type == 'x')
		write(1, "0x", 2);
	else if (flag[0] == 1 && type == 'X')
		write(1, "0X", 2);
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
