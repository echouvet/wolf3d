/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 03:19:03 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/14 14:05:11 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		sizeofstr(char const *s)
{
	int i;
	int j;

	j = 0;
	i = ft_strlen(s);
	while ((i - 1 != 0) && (s[i - 1] == ' ' || s[i - 1] == '\n' ||
		s[i - 1] == '\t'))
		i--;
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
	{
		i--;
		j++;
	}
	if (i < 0)
		i = 0;
	return (i);
}

char			*ft_strtrim(char const *s)
{
	int		i;
	int		j;
	int		k;
	char	*str;

	if (s == NULL)
		return (NULL);
	i = sizeofstr(s);
	j = 0;
	k = 0;
	str = (char*)malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	while (s[j] == ' ' || s[j] == '\n' || s[j] == '\t')
		j++;
	while (k < i)
	{
		str[k] = s[j];
		k++;
		j++;
	}
	str[k] = '\0';
	return (str);
}
