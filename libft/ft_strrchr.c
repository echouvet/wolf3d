/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:47:25 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/10 19:47:26 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;

	i = ft_strlen(s);
	if (c == '\0')
		return ((char*)s + i);
	while (i != 0)
	{
		i--;
		if (s[i] == c)
			return ((char*)s + i);
	}
	return (NULL);
}
