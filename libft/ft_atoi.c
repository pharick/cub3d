/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:31:54 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/06 12:31:34 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v' ||
			c == '\f' || c == '\r' || c == ' ');
}

int			ft_atoi(const char *str)
{
	long	n;
	int		is_minus;
	long	next;

	while (ft_isspace(*str))
		str++;
	is_minus = (*str == '-');
	if (*str == '-' || *str == '+')
		str++;
	n = 0;
	while (*str >= '0' && *str <= '9')
	{
		next = n * 10 + (*str - '0');
		if (next < n)
			return (is_minus ? 0 : -1);
		n = next;
		str++;
	}
	return (int)(is_minus ? -n : n);
}
