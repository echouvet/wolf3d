/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:05:31 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/12 22:05:34 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrev(char *str)
{
	int i;
	int c;
	int b;

	i = 0;
	b = 0;
	i = ft_strlen(str) - 1;
	while (b < i)
	{
		c = str[b];
		str[b] = str[i];
		str[i] = c;
		b++;
		i--;
	}
	return (str);
}
