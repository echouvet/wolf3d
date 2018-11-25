/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wolf.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 19:08:00 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/23 19:08:01 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WOLF_H
# define WOLF_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>
# include <fcntl.h>

typedef	struct	s_tex
{
	void		*img;
	int			*pxl;
}				t_tex;

typedef	struct	s_raycast
{
	double		posx;
	double		posy;
	double		dirx;
	double		diry;
	double		planex;
	double		planey;
	double		movespeed;
	double		rot;
	double		camerax;
	double		raydirx;
	double		raydiry;
	int			mapx;
	int			mapy;
	double		sidedistx;
	double		sidedisty;
	double		deltadistx;
	double		deltadisty;
	double		wd;
	int			stepx;
	int			stepy;
	int			side;
	int			lh;
	int			drawstart;
	int			drawend;
	double		wallx;
	int			texoption;
}				t_raycast;

typedef	struct	s_env
{
	int			**map;
	char		*name;
	void		*img;
	void		*mlx;
	void		*win;
	int			bpp;
	int			s_l;
	int			edn;
	int			x;
	int			y;
	int			w;
	int			h;
	int			*pixels;
	int			minimap;
	t_raycast	r;
	t_tex		t[10];
}				t_env;

void			envset(t_env *e, char *file);
void			error(char *str);
int				tablen(char **tab);
void			raycasting(t_env *e);
void			moveup(t_env *e);
void			movedown(t_env *e);
void			moveright(t_env *e);
void			moveleft(t_env *e);
void			setvalues(t_env *e);
void			empty(t_env *e);
void			set_textures(t_env *e);
void			put_pixel(t_env *e, int x, int y, int color);
void			check_walls(t_env *e);
void			minimap(t_env *e);
void			background(t_env *e);

#endif
