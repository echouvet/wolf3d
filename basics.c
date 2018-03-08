/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   basics.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 23:14:35 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/23 23:14:37 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	error(char *str)
{
	if (ft_strcmp(str, "usage") == 0)
		ft_putendl("Usage Error: Please read the README file");
	if (ft_strcmp(str, "malloc") == 0)
		ft_putendl("Error: Memory allocation failed");
	if (ft_strcmp(str, "textures") == 0)
		ft_putendl("Error: Failed to load textures");
	exit(0);
}

int		tablen(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
	return (i);
}

void	empty(t_env *e)
{
	int i;

	i = 0;
	while (i < e->h * e->w)
	{
		e->pixels[i] = 0x000000;
		i++;
	}
}

void	put_pixel(t_env *e, int x, int y, int color)
{
	if (x >= 0 && x < e->w && y >= 0 && y < e->h)
		e->pixels[y * e->w + x] = color;
}
