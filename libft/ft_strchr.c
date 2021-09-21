/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 18:41:41 by cbelva            #+#    #+#             */
/*   Updated: 2020/10/29 18:51:14 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	char	*s_iter;

	s_iter = (char*)s;
	while (*s_iter)
	{
		if (*s_iter == (char)c)
			return (s_iter);
		s_iter++;
	}
	return (*s_iter == (char)c ? s_iter : NULL);
}
