/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 21:45:08 by cbelva            #+#    #+#             */
/*   Updated: 2020/10/30 00:09:18 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	*s_iter;

	s_iter = (char*)s;
	len = 0;
	while (*s_iter)
	{
		len++;
		s_iter++;
	}
	while (len > 0)
	{
		if (*s_iter == (char)c)
			return (s_iter);
		s_iter--;
		len--;
	}
	return (*s_iter == (char)c ? s_iter : NULL);
}
