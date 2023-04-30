/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_write_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:16 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:34 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_write_bonus.h"

static void	char_write2(unsigned char c, int *flag);

void	char_write(int *count, t_type *node, unsigned char c)
{
	int	flag[4];
	int	full_size;

	full_size = 1;
	flag[1] = 0;
	flag[3] = 0;
	if (node -> minus > full_size)
		flag[3] = node -> minus - 1;
	else if (node -> width > full_size)
		flag[1] = node -> width - 1;
	full_size += (flag[1] + flag[3]);
	(*count) += full_size;
	char_write2(c, flag);
}

static void	char_write2(unsigned char c, int *flag)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	write(1, &c, 1);
	while (flag[3]-- > 0)
		write(1, " ", 1);
}
