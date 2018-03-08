/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 16:29:36 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/27 16:29:37 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

void	set_textures_nesw(t_env *e, char *pixels, int i, int j)
{
	e->t[6].img = mlx_xpm_file_to_image(e->mlx, "textures/North.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[6].img, &e->bpp, &e->s_l, &e->edn);
	e->t[6].pxl = (int*)pixels;
	e->t[7].img = mlx_xpm_file_to_image(e->mlx, "textures/South.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[7].img, &e->bpp, &e->s_l, &e->edn);
	e->t[7].pxl = (int*)pixels;
	e->t[8].img = mlx_xpm_file_to_image(e->mlx, "textures/East.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[8].img, &e->bpp, &e->s_l, &e->edn);
	e->t[8].pxl = (int*)pixels;
	e->t[9].img = mlx_xpm_file_to_image(e->mlx, "textures/West.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[9].img, &e->bpp, &e->s_l, &e->edn);
	e->t[9].pxl = (int*)pixels;
}

void	set_textures_2(t_env *e, int i, int j)
{
	char	*pixels;

	e->t[3].img = mlx_xpm_file_to_image(e->mlx, "textures/colorstone.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[3].img, &e->bpp, &e->s_l, &e->edn);
	e->t[3].pxl = (int*)pixels;
	e->t[4].img = mlx_xpm_file_to_image(e->mlx, "textures/mossy.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[4].img, &e->bpp, &e->s_l, &e->edn);
	e->t[4].pxl = (int*)pixels;
	e->t[5].img = mlx_xpm_file_to_image(e->mlx, "textures/redbrick.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[5].img, &e->bpp, &e->s_l, &e->edn);
	e->t[5].pxl = (int*)pixels;
}

void	set_textures(t_env *e)
{
	char	*pixels;
	int		i;
	int		j;

	e->t[0].img = mlx_xpm_file_to_image(e->mlx, "textures/greystone.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[0].img, &e->bpp, &e->s_l, &e->edn);
	e->t[0].pxl = (int*)pixels;
	e->t[1].img = mlx_xpm_file_to_image(e->mlx, "textures/purplestone.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[1].img, &e->bpp, &e->s_l, &e->edn);
	e->t[1].pxl = (int*)pixels;
	e->t[2].img = mlx_xpm_file_to_image(e->mlx, "textures/wood.xpm",
		&i, &j);
	pixels = mlx_get_data_addr(e->t[2].img, &e->bpp, &e->s_l, &e->edn);
	e->t[2].pxl = (int*)pixels;
	set_textures_2(e, i, j);
	set_textures_nesw(e, pixels, i, j);
	if (!(e->t[1].img) || !(e->t[2].img) || !(e->t[3].img) || !(e->t[4].img)
		|| !(e->t[5].img) || !(e->t[6].img) || !(e->t[0].img) || !(e->t[7].img)
		|| !(e->t[8].img) || !(e->t[9].img))
		error("textures");
}
