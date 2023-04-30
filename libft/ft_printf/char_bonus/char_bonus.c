/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:36:14 by byelee            #+#    #+#             */
/*   Updated: 2023/01/18 14:36:34 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char_bonus.h"
#include "char_write_bonus.h"

void	char_main(int *count, t_type *node, va_list ap)
{
	unsigned char	input;

	input = (unsigned char)va_arg(ap, int);
	char_write(count, node, input);
}
