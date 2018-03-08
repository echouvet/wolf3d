/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 16:11:33 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/12 16:11:35 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*new;

	if (!(new = (t_list*)malloc(sizeof(t_list))))
		return (NULL);
	if (!((*new).content = (void*)malloc(content_size)))
		return (NULL);
	(*new).next = NULL;
	if (content == NULL)
	{
		(*new).content = (NULL);
		(*new).content_size = 0;
		return (new);
	}
	(*new).content_size = content_size;
	(*new).content = ft_memcpy(new->content, content, content_size);
	return (new);
}
