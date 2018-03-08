/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 22:42:22 by echouvet          #+#    #+#             */
/*   Updated: 2018/02/23 22:42:23 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf.h"

char		**fileread(const int fd, int size, int counter)
{
	char	buffer[4097];
	char	*str;
	char	**tab;
	char	*tmp;

	if (!(str = ft_strdup("")))
		error("malloc");
	while (size > 0)
	{
		if (((size = read(fd, buffer, 4096)) && size == -1))
			error("usage");
		buffer[size] = 0;
		if (!(tmp = ft_strjoin(str, buffer)))
			error("malloc");
		free(str);
		if (!(str = ft_strdup(tmp)))
			error("malloc");
		free(tmp);
		if (counter++ > 10)
			error("usage");
	}
	if (!(tab = ft_splitstr(str, '\n')))
		error("malloc");
	free(str);
	return (tab);
}

/*
** verifies that the outer walls of the map are filled,
** and that the map isn't too big
*/

void		check_walls(t_env *e)
{
	int i;

	if (e->x < 4 || e->y < 4 || e->x > 100 || e->y > 100)
		error("usage");
	if (e->map[1][1] != 0)
		error("usage");
	i = 0;
	while (i < e->y)
	{
		if (e->map[i][0] == 0 || e->map[i][e->x - 1] == 0)
			error("usage");
		i++;
	}
	i = 0;
	while (i < e->x)
	{
		if (e->map[0][i] == 0 || e->map[e->y - 1][i] == 0)
			error("usage");
		i++;
	}
}

/*
** Places the data into a double array of int
** Verifies that each number is between 0 and 6 and lines are same length
*/

void		mapset(t_env *e, char ***data)
{
	int i;
	int j;

	i = 0;
	if (!(e->map = (int**)malloc(sizeof(int*) * e->y)))
		error("malloc");
	while (i != e->y)
	{
		j = 0;
		if (!(e->map[i] = (int*)malloc(sizeof(int) * e->x)))
			error("malloc");
		while (j != e->x)
		{
			e->map[i][j] = ft_atoi(data[i][j]);
			if (e->map[i][j] < 0 || e->map[i][j] > 6)
				error("usage");
			free(data[i][j]);
			j++;
		}
		free(data[i]);
		i++;
	}
	check_walls(e);
	free(data);
}

/*
** seperates the data into a tripple array
*/

void		dataset(t_env *e, char **map)
{
	char	***data;
	int		i;

	i = 0;
	if (!(data = (char***)malloc(sizeof(char**) * e->y)))
		error("malloc");
	while (i != e->y)
	{
		if (!(data[i] = ft_strsplit(map[i], ' ')))
			error("malloc");
		free(map[i]);
		i++;
	}
	free(map);
	mapset(e, data);
}

void		envset(t_env *e, char *file)
{
	char	*pixels;
	char	**map;
	int		tmp;
	int		fd;

	fd = open(file, O_RDONLY);
	e->y = 0;
	e->name = file;
	map = fileread(fd, 42, 0);
	if (map[0] == NULL)
		error("usage");
	while (map[e->y])
	{
		if ((!(tmp = tablen(ft_strsplit(map[e->y], ' ')))) ||
			(e->y != 0 && tmp != e->x))
			error("usage");
		e->x = tmp;
		e->y++;
	}
	dataset(e, map);
	e->mlx = mlx_init();
	e->img = mlx_new_image(e->mlx, e->w, e->h);
	e->win = mlx_new_window(e->mlx, e->w, e->h, e->name);
	pixels = mlx_get_data_addr(e->img, &e->bpp, &e->s_l, &e->edn);
	e->pixels = (int*)pixels;
}
