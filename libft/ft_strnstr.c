/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 18:59:00 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/10 18:59:01 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *hay, const char *needle, size_t len)
{
	size_t i;
	size_t j;

	i = 0;
	if (needle[i] == '\0')
		return ((char*)hay);
	while (hay[i] && i < len)
	{
		j = 0;
		while (hay[i + j] == needle[j] && (i + j < len))
		{
			j++;
			if (needle[j] == '\0')
				return ((char*)hay + i);
		}
		i++;
	}
	return (NULL);
}
