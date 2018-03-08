/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 00:39:04 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/24 00:39:05 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** defines which texture to use, the option is defined by keys.
** if option is 1, then texture is defined by the direction a wall is facing.
** if option is 0, mapx and mapy are used to know which wall we're looking at.
*/

void	texnum(t_env *e)
{
	if (e->r.texoption == 0)
		e->r.texnum = e->map[e->r.mapx][e->r.mapy] - 1;
	else
	{
		if (e->r.side == 0 && e->r.raydirx < 0)
			e->r.texnum = 6;
		if (e->r.side == 0 && e->r.raydirx >= 0)
			e->r.texnum = 7;
		if (e->r.side == 1 && e->r.raydiry >= 0)
			e->r.texnum = 8;
		if (e->r.side == 1 && e->r.raydiry < 0)
			e->r.texnum = 9;
	}
}

/*
** initially I had varibles for the height and width of each textures
** I made every texture 64 wide and 64 long, so I put 64 everywhere
**
** wallx is the exact value of where a wall was hit. I subtract the int
** value to just have the position on a specific wall.
** I then multiply this by the width to get the x coordinate of the texture.
**
** the first if will inverse the calculation if we're looking in the
** negative direction. This makes it so that the texture isn't upside down
**
** While loop allows us to find exact color for each pixel on the line.
**
//						texy's equation is magic, please explain it to me if you get it.
**
** Now that I know the x and y value of my texture, I set my color
** to the color in the texture which I'd retrieved in texture.c
**
** if I'm using option 1, and I'm on a y side, I now make it darker
** by dividing by 2 through a bitshift, and "AND-ing" the value with
** the binary value 011111110111111101111111 so that the colors
** don't overlap. Basically this makes a shadow effect.
**
** I then place my pixel in my window. put_pixel is in basics.c.
*/

void	put_textures(t_env *e, int x)
{
	int y;
	int color;
	int texx;
	int texy;

	e->r.wallx -= (int)(e->r.wallx);
	texx = (int)(e->r.wallx * 64);
	if ((e->r.side == 0 && e->r.raydirx > 0) ||
		(e->r.side == 1 && e->r.raydiry < 0))
		texx = 64 - texx - 1;
	y = e->r.drawstart;
	while (y < e->r.drawend)
	{
		texy = (((y * 256 - e->h * 128 + e->r.lh * 128) * 64) / e->r.lh / 256);
		color = e->t[e->r.texnum].pxl[64 * texy + texx];
		if (e->r.side == 1 && e->r.texoption == 0)
			color = (color >> 1) & 0x7F7F7F;
		put_pixel(e, x, y, color);
		y++;
	}
}

/*
** this is where I cast my rays to find walls :)
** The while loop will run until the side of a wall is hit.
** I've defined 0s as free spaces to move through.
** Sidedist x & y allow us to know which line is longer. We perpetually increase
** the shorter one, to eventually find the first wall that hits.
** Side stores whether an x wall or a y wall was hit.
** We'll know exactly which wall was hit with mapx and mapy.
**
** We then calculate wd: wall distance from player:
** (1 - e->r.stepx) / 2) = is 1 if stepx is -1 and 0 if stepx is 1,
** this is calculated since 1 must be added if looking back.
** map x & y would be the position of the wall. Subrtracting pos gives us
** a straight distance. To get the real distance this is devided by the
** ray's diraction.
**
** wallx is the exact distance where the wall was hit. This is is for later,
** it will help calculate the x coordinate of the texture (texx).
*/

void	side_and_walldist(t_env *e)
{
	while (e->map[e->r.mapx][e->r.mapy] == 0)
	{
		if (e->r.sidedistx < e->r.sidedisty)
		{
			e->r.sidedistx += e->r.deltadistx;
			e->r.mapx += e->r.stepx;
			e->r.side = 0;
		}
		else
		{
			e->r.sidedisty += e->r.deltadisty;
			e->r.mapy += e->r.stepy;
			e->r.side = 1;
		}
	}
	if (e->r.side == 0)
	{
		e->r.wd = (e->r.mapx - e->r.posx + (1 - e->r.stepx) / 2) / e->r.raydirx;
		e->r.wallx = e->r.posy + e->r.wd * e->r.raydiry;
	}
	else
	{
		e->r.wd = (e->r.mapy - e->r.posy + (1 - e->r.stepy) / 2) / e->r.raydiry;
		e->r.wallx = e->r.posx + e->r.wd * e->r.raydirx;
	}
}

/*
** for now, sidedist x & y is the distance the ray has to travel
** from (posx, posy) to the first upcomming x and y side.
** it's calculates to the left if negative, and to the right if raydir positive
** step is 1 if I'm looking foreward and -1 if I'm looking backwards, for x & y
** stepx and stepy will allow me to know if I need to go in the positive or
** negative direction when I calculate the distante to first wall.
*/

void	step_and_sidedist(t_env *e)
{
	if (e->r.raydirx < 0)
	{
		e->r.stepx = -1;
		e->r.sidedistx = (e->r.posx - e->r.mapx) * e->r.deltadistx;
	}
	else
	{
		e->r.stepx = 1;
		e->r.sidedistx = (e->r.mapx + 1.0 - e->r.posx) * e->r.deltadistx;
	}
	if (e->r.raydiry < 0)
	{
		e->r.stepy = -1;
		e->r.sidedisty = (e->r.posy - e->r.mapy) * e->r.deltadisty;
	}
	else
	{
		e->r.stepy = 1;
		e->r.sidedisty = (e->r.mapy + 1.0 - e->r.posy) * e->r.deltadisty;
	}
}

/*
** while loop will run for every vertial stripe (1500 times)
** camerax goes from -1 to 1: it's the relative diffenrence between each line.
** raydir are the direction/position a ray will be cast. The dir and plane are
** defined by the rotation matrixes in move.c.
** mapx and mapy are the square of the map the ray is in. it casts pos as int
** to get the map position of the character for raycasting calculations.
**
** deltadist is  is the distance from one x or y side to the next.
** delta dist can be calculated through pythagorus, but I use a simplification:
** exp: "deltadirx = sqrt(1 + (raydiry * raydiry) / (raydirx * raydirx))"
**
** The wall distance is calculated, which is used to find the lineheight: (lh)
** The height of the window defines the wall's height.
** drawstart and drawend will be half of lineheight subtracted/added to half
** the window, this will define the limits of my vertical line for the wall.
**
** I then find out which texture I'm using and I set the texture to my line.
*/

void	raycasting(t_env *e)
{
	int x;

	x = 0;
	while (x < e->w)
	{
		e->r.camerax = (2 * x) / (double)e->w - 1;
		e->r.raydirx = e->r.dirx + e->r.planex * e->r.camerax;
		e->r.raydiry = e->r.diry + e->r.planey * e->r.camerax;
		e->r.mapx = e->r.posx;
		e->r.mapy = e->r.posy;
		e->r.deltadistx = fabs(1 / e->r.raydirx);
		e->r.deltadisty = fabs(1 / e->r.raydiry);
		step_and_sidedist(e);
		side_and_walldist(e);
		e->r.lh = (int)(e->h / e->r.wd);
		e->r.drawstart = -e->r.lh / 2 + e->h / 2;
		if (e->r.drawstart < 0)
			e->r.drawstart = 0;
		e->r.drawend = e->r.lh / 2 + e->h / 2;
		if (e->r.drawend >= e->h)
			e->r.drawend = e->h - 1;
		texnum(e);
		put_textures(e, x);
		x++;
	}
}
