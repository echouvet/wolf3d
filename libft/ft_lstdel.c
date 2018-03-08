/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 17:19:34 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/12 17:19:36 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list	*current;
	t_list	*new;

	current = *alst;
	while (current)
	{
		new = current->next;
		ft_lstdelone(&current, del);
		current = new;
	}
	*alst = NULL;
}
