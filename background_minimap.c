/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/06 18:13:14 by echouvet          #+#    #+#             */
/*   Updated: 2018/03/06 18:13:15 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	background(t_env *e)
{
	int i;

	i = 0;
	while (i < (e->w * e->h) / 2)
	{
		if (e->pixels[i] == 0x000000)
			e->pixels[i] = 0x66B2FFl;
		i++;
	}
	while (i < e->w * e->h)
	{
		if (e->pixels[i] == 0x000000)
			e->pixels[i] = 0x336600;
		i++;
	}
}

/*
** each block on the minimap will be 5 pixels by 5 pixels.
** i is counter to 5 for x value and j is counter for y value
** (20, 20) is the starting position of the map on the window
*/

void	draw_square(t_env *e, int x, int y, int color)
{
	int	i;
	int	j;

	j = 20;
	while (j < 25)
	{
		i = 20;
		while (i < 25)
		{
			put_pixel(e, ((x * 5) + i), ((y * 5) + j), color);
			i++;
		}
		j++;
	}
}

void	minimap(t_env *e)
{
	int x;
	int y;

	y = 0;
	while (y < e->y)
	{
		x = 0;
		while (x < e->x)
		{
			if (e->map[y][x] == 0)
				draw_square(e, x, y, 0x000000);
			else
				draw_square(e, x, y, 0xFFFFFF);
			x++;
		}
		y++;
	}
	draw_square(e, (int)e->r.posy, (int)e->r.posx, 0xFF0000);
}
