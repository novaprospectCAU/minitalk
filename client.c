/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:49:40 by byelee            #+#    #+#             */
/*   Updated: 2023/04/28 14:49:44 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	transmit_signal(pid_t pid, char *str, size_t len)
{
	size_t	byte_idx;
	int		bit_idx;
	int		temp;

	byte_idx = 0;
	while (byte_idx < len)
	{
		bit_idx = 0;
		while (bit_idx < 8)
		{
			temp = (str[byte_idx] >> (7 - bit_idx) & 1);
			if (temp == 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(80);
			bit_idx++;
		}
		byte_idx++;
	}
}

void	error_output(int err_num)
{
	if (err_num == 0)
		ft_printf("Invalid input. I think you missed PID or input String.\n");
	else if (err_num == 1)
		ft_printf("invalid input, Your PID has gone beyond the boundary.\n");
	else
		ft_printf("Error : dynamic allocation error occurred\n");
}

int	main(int argc, char *argv[])
{
	char	*str;
	size_t	idx;
	size_t	length;
	pid_t	pid;

	if (argc != 3)
		return (error_output(0));
	pid = (pid_t)ft_atoi(argv[1]);
	if (pid < 100 || pid > 99998)
		return (error_output(1));
	idx = 0;
	while (argv[2][idx])
		idx++;
	length = idx;
	str = ft_strjoin(argv[2], "\n");
	if (str == NULL)
		return (error_output(2));
	transmit_signal(pid, str, length);
	return (0);
}
