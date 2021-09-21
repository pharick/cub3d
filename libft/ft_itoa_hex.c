/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_hex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 10:59:33 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/01 09:34:53 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static size_t	ft_count_digits(long number, int is_minus)
{
	size_t	len;

	len = 1;
	number /= 16;
	while (number)
	{
		number /= 16;
		len++;
	}
	if (is_minus)
		len++;
	return (len);
}

static char		ft_getdigit(int d, int upper)
{
	if (d >= 0 && d <= 9)
		return (d + '0');
	if (d <= 16)
		return (d - 10 + (upper ? 'A' : 'a'));
	return ('\0');
}

char			*ft_itoa_hex(long n, int upper)
{
	size_t	len;
	long	number;
	int		is_minus;
	char	*result;
	char	*iter;

	is_minus = n < 0;
	number = n < 0 ? -n : n;
	len = ft_count_digits(number, is_minus);
	result = (char*)malloc((len + 1) * sizeof(char));
	if (result == NULL)
		return (NULL);
	iter = result + len;
	*(iter--) = '\0';
	number = is_minus ? -(long)n : n;
	*(iter--) = ft_getdigit(number % 16, upper);
	number /= 16;
	while (number)
	{
		*(iter--) = ft_getdigit(number % 16, upper);
		number /= 16;
	}
	if (is_minus)
		*iter = '-';
	return (result);
}
