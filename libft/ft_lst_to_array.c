/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_to_array.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbelva <cbelva@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/12/22 12:29:45 by cbelva            #+#    #+#             */
/*   Updated: 2020/12/30 14:52:47 by cbelva           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	**ft_lst_to_array(t_list *lst)
{
	t_list	*node;
	void	**array;
	void	**iter;

	if (lst == NULL)
		return (NULL);
	array = (void**)malloc(ft_lstsize(lst) * sizeof(void*));
	if (array == NULL)
		return (NULL);
	iter = array;
	node = lst;
	while (node)
	{
		*iter = node->content;
		node = node->next;
		iter++;
	}
	return (array);
}
