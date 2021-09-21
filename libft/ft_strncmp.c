/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:12:11 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/05 14:44:40 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_iter;
	unsigned char	*s2_iter;

	if (n == 0)
		return (0);
	s1_iter = (unsigned char*)s1;
	s2_iter = (unsigned char*)s2;
	while (*s1_iter && (*s1_iter == *s2_iter) && (n > 1))
	{
		s1_iter++;
		s2_iter++;
		n--;
	}
	return (*s1_iter - *s2_iter);
}
