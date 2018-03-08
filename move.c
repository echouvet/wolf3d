/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/24 03:19:06 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/24 03:19:07 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

/*
** dirx and diry are added/subtracted to posx and posy respectively to move.
** the 'if's will make it so that you don't move if you hit a wall.
*/

void	moveup(t_env *e)
{
	if ((e->map[(int)(e->r.posx + e->r.dirx * e->r.movespeed)][(int)e->r.posy])
		== 0)
		e->r.posx += e->r.dirx * e->r.movespeed;
	if ((e->map[(int)e->r.posx][(int)(e->r.posy + e->r.diry * e->r.movespeed)])
		== 0)
		e->r.posy += e->r.diry * e->r.movespeed;
}

void	movedown(t_env *e)
{
	if ((e->map[(int)(e->r.posx - e->r.dirx * e->r.movespeed)][(int)e->r.posy])
		== 0)
		e->r.posx -= e->r.dirx * e->r.movespeed;
	if ((e->map[(int)e->r.posx][(int)(e->r.posy - e->r.diry * e->r.movespeed)])
		== 0)
		e->r.posy -= e->r.diry * e->r.movespeed;
}

/*
** dir and plane calculated through rotation matrixes over the angle rot (0.1)
** They stay perpendicular which allows for the FOV to stay unchanged.
*/

void	moveright(t_env *e)
{
	double olddirx;
	double tmpplanex;

	olddirx = e->r.dirx;
	e->r.dirx = e->r.dirx * cos(-e->r.rot) - e->r.diry * sin(-e->r.rot);
	e->r.diry = olddirx * sin(-e->r.rot) + e->r.diry * cos(-e->r.rot);
	tmpplanex = e->r.planex;
	e->r.planex = e->r.planex * cos(-e->r.rot) - e->r.planey * sin(-e->r.rot);
	e->r.planey = tmpplanex * sin(-e->r.rot) + e->r.planey * cos(-e->r.rot);
}

void	moveleft(t_env *e)
{
	double olddirx;
	double tmpplanex;

	olddirx = e->r.dirx;
	e->r.dirx = e->r.dirx * cos(e->r.rot) - e->r.diry * sin(e->r.rot);
	e->r.diry = olddirx * sin(e->r.rot) + e->r.diry * cos(e->r.rot);
	tmpplanex = e->r.planex;
	e->r.planex = e->r.planex * cos(e->r.rot) - e->r.planey * sin(e->r.rot);
	e->r.planey = tmpplanex * sin(e->r.rot) + e->r.planey * cos(e->r.rot);
}
