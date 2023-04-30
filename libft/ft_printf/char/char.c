/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   char.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 11:46:29 by byelee            #+#    #+#             */
/*   Updated: 2023/01/19 11:46:32 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "char.h"

void	char_main(int *count, va_list ap)
{
	unsigned char	input;

	input = (unsigned char)va_arg(ap, int);
	write(1, &input, 1);
	(*count)++;
}
