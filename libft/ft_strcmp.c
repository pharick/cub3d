/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 11:12:11 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/17 16:05:54 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*s1_iter;
	unsigned char	*s2_iter;

	s1_iter = (unsigned char*)s1;
	s2_iter = (unsigned char*)s2;
	while (*s1_iter && (*s1_iter == *s2_iter))
	{
		s1_iter++;
		s2_iter++;
	}
	return (*s1_iter - *s2_iter);
}
