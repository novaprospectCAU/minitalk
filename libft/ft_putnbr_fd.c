/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:42 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:39 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fs_check_special(int *n, const int fd)
{
	if (*n == 0)
	{
		write(fd, "0", 1);
		return (0);
	}
	if (*n == -2147483648)
	{
		write(fd, "-2147483648", 11);
		return (0);
	}
	if (*n < 0)
	{
		write(fd, "-", 1);
		*n *= -1;
	}
	return (1);
}

void	ft_putnbr_fd(int n, int fd)
{
	int		index;
	char	arr[11];

	index = 0;
	if (!fs_check_special(&n, fd))
		return ;
	while (n > 0)
	{
		arr[index++] = (char)(n % 10 + '0');
		n /= 10;
	}
	while (--index >= 0)
		write(fd, &arr[index], 1);
}
