/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: echouvet <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/17 15:07:12 by echouvet          #+#    #+#             */
/*   Updated: 2017/12/11 21:55:49 by echouvet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**fileread(const int fd)
{
	int		size;
	char	buffer[BUFF_SIZE + 1];
	char	*str;
	char	**tab;
	char	*tmp;

	if (!(str = ft_strdup("")))
		return (NULL);
	size = 42;
	while (size > 0)
	{
		if ((size = read(fd, buffer, BUFF_SIZE)) && size == -1)
			return (NULL);
		buffer[size] = 0;
		if (!(tmp = ft_strjoin(str, buffer)))
			return (NULL);
		free(str);
		if (!(str = ft_strdup(tmp)))
			return (NULL);
		free(tmp);
	}
	if (!(tab = ft_splitstr(str, '\n')))
		return (NULL);
	free(str);
	return (tab);
}

int			get_next_line(const int fd, char **line)
{
	static t_files	s[OPEN_MAX] = {{0, 0, 0, 0}};
	int				i;

	if (fd < 0 || BUFF_SIZE < 1 || line == NULL)
		return (-1);
	i = 0;
	while (i++ < s[0].x)
		if (s[i].fd == fd && s[i].i != 0)
		{
			*line = s[i].text[s[i].i];
			if (!(s[i].text[s[i].i]))
				return (0);
			s[i].i++;
			return (1);
		}
	s[0].x++;
	s[i].fd = fd;
	if (!(s[i].text = fileread(fd)))
		return (-1);
	*line = s[i].text[s[i].i];
	if (!(s[i].text[s[i].i++]))
		return (0);
	return (1);
}
