/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/11 20:10:18 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/11 20:10:22 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		numwords(char const *s, char c)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		j++;
	}
	return (j);
}

static char		*word(char const *s, char c)
{
	int		i;
	char	*word;

	i = 0;
	while (s[i] != c && s[i])
		i++;
	word = (char*)malloc(sizeof(char) * i + 1);
	if (word == NULL)
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

char			**ft_strsplit(char const *s, char c)
{
	int		f;
	int		i;
	char	**final;

	f = 0;
	i = 0;
	if (s == NULL)
		return (NULL);
	final = (char**)malloc(sizeof(char*) * (numwords(s, c) + 1));
	if (final == NULL)
		return (NULL);
	while (s[i])
	{
		if (s[i] != c)
		{
			final[f] = word(s + i, c);
			while (s[i] != c && s[i])
				i++;
			f++;
		}
		if (s[i] == c)
			i++;
	}
	final[f] = 0;
	return (final);
}
