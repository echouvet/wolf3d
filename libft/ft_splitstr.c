/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_splitstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/10 18:01:10 by echouvet          #+#    #+#             */
/*   Updated: 2017/12/10 18:01:11 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numtabs(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] == c)
			j++;
		i++;
	}
	if (s[i - 1] != c)
		j++;
	return (j);
}

static char		*word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	if (!(word = (char*)malloc(sizeof(char) * i + 1)))
		return (NULL);
	i = 0;
	while (s[i] != c && s[i])
	{
		word[i] = s[i];
		i++;
	}
	word[i] = '\0';
	return (word);
}

char			**ft_splitstr(char const *s, char c)
{
	int		f;
	int		i;
	char	**final;

	f = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(final = (char**)malloc(sizeof(char*) * (numtabs(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		final[f] = word(s + i, c);
		while (s[i] != c && s[i])
			i++;
		f++;
		if (s[i])
			i++;
	}
	final[f] = 0;
	return (final);
}
