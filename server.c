/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/28 14:50:32 by byelee            #+#    #+#             */
/*   Updated: 2023/04/28 14:50:33 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	signal_handler(int sig)
{
	static char	output;
	static int	idx;
	char		temp;

	temp = 1;
	if (sig == SIGUSR1)
	{
		output = output | (temp << (7 - idx));
		idx++;
	}
	else
	{
		idx++;
	}
	if (idx == 8)
	{
		write(1, &output, 1);
		output = 0;
		idx = 0;
	}
}

int	main(void)
{
	ft_printf("server PID : %d\n", getpid());
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	while (1)
		pause();
	return (0);
}
