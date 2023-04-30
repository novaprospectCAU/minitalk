/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:08 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:32:53 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	fs_negative(const char *nptr)
{
	long	result_l;
	long	temp;
	int		result;

	result = 0;
	result_l = 0;
	temp = 0;
	while (*nptr && *nptr > 47 && *nptr < 58)
	{
		result *= 10;
		result_l *= 10;
		result += (*nptr - '0');
		result_l += (*nptr - '0');
		if (result_l < temp)
			return (0);
		temp = result_l;
		nptr++;
	}
	return ((int)(result * -1));
}

static int	fs_positive(const char *nptr)
{
	long	result_l;
	long	temp;
	int		result;

	result = 0;
	result_l = 0;
	temp = 0;
	while (*nptr && *nptr > 47 && *nptr < 58)
	{
		result *= 10;
		result_l *= 10;
		result += (*nptr - '0');
		result_l += (*nptr - '0');
		if (result_l < temp)
			return (-1);
		temp = result_l;
		nptr++;
	}
	return (result);
}

static int	fs_atoi(const char *nptr, int mflag)
{
	if (mflag == -1)
		return (fs_negative(nptr));
	else
		return (fs_positive(nptr));
}

int	ft_atoi(const char *nptr)
{
	int	result;
	int	mflag;

	result = 0;
	mflag = 1;
	while (*nptr && (*nptr == ' ' || *nptr == '\t' || *nptr == '\n' || \
			*nptr == '\v' || *nptr == '\f' || *nptr == '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			mflag = -1;
		nptr++;
	}
	return (fs_atoi(nptr, mflag));
}
