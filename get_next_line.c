/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:24:37 by ccorcy            #+#    #+#             */
/*   Updated: 2016/12/18 12:59:42 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

t_fd_map	*new_fd_map(int fd)
{
	t_fd_map	*result;

	if ((result = (t_fd_map *)malloc(sizeof(t_fd_map))) == NULL)
		return (NULL);
	result->content = ft_strnew(BUF_SIZE);
	result->fd = fd;
	result->next = NULL;
	return (result);
}

char		*get_content(t_fd_map *fd_map, const int fd)
{
	if (fd_map->fd == fd && fd_map->content != NULL)
		return (fd_map->content);
	while (fd_map->next != NULL)
	{
		fd_map = fd_map->next;
		if (fd_map->fd == fd)
			return (fd_map->content);
	}
	fd_map->next = new_fd_map(fd);
	fd_map = fd_map->next;
	return (fd_map->content);
}

int			end_line(char **line, t_fd_map *fd_map, const int fd, int forced)
{
	char	*save;
	char	*save_pos;
	int		i;

	i = 0;
	while (line[0][i] != 0 && line[0][i] != '\n')
		i++;
	if (line[0][i] == '\n' || forced == 1)
	{
		save = ft_strdup(*line);
		line[0][i] = '\0';
		*line = ft_strsub(*line, 0, i);
		save_pos = save;
		while (fd_map->fd != fd)
			fd_map = fd_map->next;
		save += i + 1;
		ft_strcpy(fd_map->content, save);
		ft_memdel((void *)&save_pos);
		return (1);
	}
	return (0);
}

int			get_next_line(const int fd, char **line)
{
	static t_fd_map		*fd_map;
	char				buf[BUF_SIZE + 1];
	int					ret;

	if (fd < 0 || !line)
		return (-1);
	if (!fd_map)
		fd_map = new_fd_map(fd);
	*line = get_content(fd_map, fd);
	while ((ret = read(fd, &buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		*line = ft_strjoin(*line, buf);
		if (end_line(line, fd_map, fd, 0) == 1)
			return (1);
	}
	if (ret == -1)
		return (-1);
	if (*line[0] != 0)
		return (end_line(line, fd_map, fd, 1));
	return (0);
}