/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmignot <tmignot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2013/12/02 17:01:51 by tmignot           #+#    #+#             */
/*   Updated: 2015/04/03 06:49:05 by tmignot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static void		ft_realloc(char **line, int size)
{
	char			*tmp;

	tmp = ft_strdup(*line);
	if (tmp)
	{
		free(*line);
		*line = (char*)malloc(sizeof(char) * size);
		if (*line)
		{
			ft_strcpy(*line, tmp);
			free(tmp);
		}
	}
}

static int		ft_read(char *buf, int fd, int ret)
{
	ret = read(fd, buf, BUFF_SIZE);
	if (ret < 0)
		return (-1);
	buf[ret] = '\0';
	return (ret);
}

static int		ft_is_new_line(char **line, char *buf, int i)
{
	ft_strncat(*line, buf, i);
	ft_strcpy(buf, buf + i + 1);
	return (1);
}

static int		ft_no_new_line(char **line, char *buf, int j)
{
	j++;
	ft_realloc(line, BUFF_SIZE * j + 1);
	if (*line == NULL)
		return (0);
	ft_strcat(*line, buf);
	buf[0] = '\0';
	return (j);
}

int				get_next_line(int const fd, char **line)
{
	int				ret;
	static char		buf[BUFF_SIZE + 1] = {'\0'};
	int				i;
	int				j;

	if (!(*line = ft_strnew(BUFF_SIZE + 1)))
		return (-1);
	j = 1;
	ret = 1;
	while (ret > 0)
	{
		if (buf[0] == '\0')
			if ((ret = ft_read(buf, fd, ret)) == -1)
				return (-1);
		i = 0;
		while (buf[i] && buf[i] != '\n' && ret > 0)
			i++;
		if (buf[i] == '\n' && ret > 0)
			return (ft_is_new_line(line, buf, i));
		else if (ret > 0)
			if ((j = ft_no_new_line(line, buf, j)) == 0)
				return (-1);
	}
	return (ret);
}
