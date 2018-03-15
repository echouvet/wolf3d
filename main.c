/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:06:05 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/23 19:06:07 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	setvalues(t_env *e)
{
	int i;

	e->r = (t_raycast){0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
		0, 0, 0, 0, 0, 0, 0, 0};
	e->r.posx = 1.5;
	e->r.posy = 1.5;
	e->r.dirx = -1;
	e->r.diry = 0;
	e->r.planex = 0;
	e->r.planey = 0.66;
	e->r.movespeed = 0.3;
	e->r.rot = 0.1;
	e->minimap = 1;
	i = 0;
	while (i++ < 17)
		moveright(e);
}

int		exit_hook(t_env *e)
{
	mlx_destroy_image(e->mlx, e->img);
	mlx_destroy_window(e->mlx, e->win);
	ft_memdel((void**)e->map);
	exit(42);
	return (0);
}

int		keyhooks(int key, t_env *e)
{
	if (key == 53)
		exit_hook(e);
	if (key == 51)
		setvalues(e);
	if (key == 126 || key == 13)
		moveup(e);
	if (key == 125 || key == 1)
		movedown(e);
	if (key == 124 || key == 2)
		moveright(e);
	if (key == 123 || key == 0)
		moveleft(e);
	if (key == 18 || key == 83)
		e->r.texoption = 0;
	if (key == 19 || key == 84)
		e->r.texoption = 1;
	empty(e);
	raycasting(e);
	background(e);
	if (key == 46)
		e->minimap *= -1;
	if (e->minimap == 1)
		minimap(e);
	mlx_put_image_to_window(e->mlx, e->win, e->img, 0, 0);
	return (0);
}

int		main(int argc, char **argv)
{
	t_env e;

	if (argc != 2)
		error("usage");
	e.w = 1500;
	e.h = 1000;
	envset(&e, argv[1]);
	set_textures(&e);
	setvalues(&e);
	raycasting(&e);
	background(&e);
	minimap(&e);
	mlx_put_image_to_window(e.mlx, e.win, e.img, 0, 0);
	mlx_hook(e.win, 17, 0, exit_hook, &e);
	mlx_hook(e.win, 2, 0, keyhooks, &e);
	mlx_loop(e.mlx);
	return (0);
}
