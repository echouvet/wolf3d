/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_table.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/12 22:22:27 by echouvet          #+#    #+#             */
/*   Updated: 2017/11/12 22:22:29 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_sort_wordtab(char **tab)
{
	int		i;
	char	*tmp;
	int		n;

	i = 1;
	while (tab[i])
	{
		n = 0;
		while (n < i)
		{
			if (ft_strcmp(tab[i], tab[n]) < 0)
			{
				tmp = tab[i];
				tab[i] = tab[n];
				tab[n] = tmp;
			}
			n++;
		}
		i++;
	}
}
