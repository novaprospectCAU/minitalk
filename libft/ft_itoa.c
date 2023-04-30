/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: byelee <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:30:23 by byelee            #+#    #+#             */
/*   Updated: 2022/11/09 14:31:31 by byelee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*if_zero(void)
{
	char	*result;

	result = malloc(2);
	if (result == NULL)
		return (NULL);
	*(result) = '0';
	*(result + 1) = '\0';
	return (result);
}

static char	*if_min(void)
{
	char	*result;

	result = malloc(12);
	if (result == NULL)
		return (NULL);
	*result++ = '-';
	*result++ = '2';
	*result++ = '1';
	*result++ = '4';
	*result++ = '7';
	*result++ = '4';
	*result++ = '8';
	*result++ = '3';
	*result++ = '6';
	*result++ = '4';
	*result++ = '8';
	*result = '\0';
	result -= 11;
	return (result);
}

static char	*if_positive(int n)
{
	char	*result;
	int		n_copy;
	int		radix;

	radix = 0;
	n_copy = n;
	while (n_copy > 0)
	{
		radix++;
		n_copy /= 10;
	}
	result = malloc(radix + 1);
	if (result == NULL)
		return (NULL);
	result += radix;
	*result-- = '\0';
	while (n > 0)
	{
		*result-- = (char)((n % 10) + '0');
		n /= 10;
	}
	result++;
	return (result);
}

static char	*if_negative(int n)
{
	char	*result;
	int		n_copy;
	int		radix;

	n *= -1;
	n_copy = n;
	radix = 0;
	while (n_copy > 0)
	{
		radix++;
		n_copy /= 10;
	}
	result = malloc(radix + 2);
	if (result == NULL)
		return (NULL);
	result += (radix + 1);
	*result-- = '\0';
	while (n > 0)
	{
		*result-- = (char)((n % 10) + '0');
		n /= 10;
	}
	*result = '-';
	return (result);
}

char	*ft_itoa(int n)
{
	if (n == 0)
		return (if_zero());
	else if (n == -2147483648)
		return (if_min());
	else if (n > 0)
		return (if_positive(n));
	else
		return (if_negative(n));
}
