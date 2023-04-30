/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string_write_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:27 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:44 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string_write_bonus.h"

static void	string_flag_if(t_type *node, int *full_size, int *flag);
static void	string_flag_elif(t_type *node, int *full_size, int *flag);
static void	string_write2(char *s, int len, int *flag);

void	string_write(int *count, t_type *node, char *s, int len)
{
	int	flag[4];
	int	full_size;
	int	output_len;

	flag[0] = 0;
	flag[1] = 0;
	flag[2] = 0;
	flag[3] = 0;
	if (node -> precision > -1 && node -> precision < len)
		output_len = node -> precision;
	else
		output_len = len;
	full_size = output_len;
	if (node -> minus > full_size)
		string_flag_if(node, &full_size, flag);
	else if (node -> width > full_size)
		string_flag_elif(node, &full_size, flag);
	(*count) += full_size;
	string_write2(s, output_len, flag);
}

static void	string_flag_if(t_type *node, int *full_size, int *flag)
{
	flag[3] = node -> minus - *full_size;
	(*full_size) += flag[3];
}

static void	string_flag_elif(t_type *node, int *full_size, int *flag)
{
	flag[1] = node -> width - *full_size;
	(*full_size) += flag[1];
}

static void	string_write2(char *s, int len, int *flag)
{
	while (flag[1]-- > 0)
		write(1, " ", 1);
	while (len-- > 0)
	{
		write(1, s, 1);
		s++;
	}
	while (flag[3]-- > 0)
		write(1, " ", 1);
}
