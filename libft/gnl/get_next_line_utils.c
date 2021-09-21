/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/11 18:35:43 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/20 16:32:40 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int			ft_strccat(char *dst, char *src, char c)
{
	int i;

	while (*dst)
		dst++;
	i = 0;
	while (*src && (*src != c))
	{
		*(dst++) = *(src++);
		i++;
	}
	*dst = '\0';
	return (i);
}
