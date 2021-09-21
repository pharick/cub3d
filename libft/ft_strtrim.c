/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/02 00:02:21 by cbelva            #+#    #+#             */
/*   Updated: 2020/11/06 11:00:26 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_is_in_set(const char c, const char *set)
{
	while (*set)
	{
		if (c == *(set++))
			return (1);
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	size_t		len;
	char		*iter;

	if (s1 == NULL || set == NULL)
		return (NULL);
	while (ft_is_in_set(*s1, set))
		s1++;
	if (*s1 == '\0')
		return (ft_strdup(""));
	len = 0;
	iter = (char*)s1;
	while (*iter)
	{
		iter++;
		len++;
	}
	iter--;
	while (ft_is_in_set(*(iter--), set))
		len--;
	return (ft_substr(s1, 0, len));
}
