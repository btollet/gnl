/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 14:24:37 by ccorcy            #+#    #+#             */
/*   Updated: 2016/12/09 15:51:20 by ccorcy           ###   ########.fr       */
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

char	*get_content(t_fd_map *fd_map, const int fd)
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

int		end_line(char *save, char **line, t_fd_map *fd_map, const int fd)
{
	int		i;

	i = 0;
	while (save[i])
	{
		if (save[i] == '\n')
		{
			save[i] = '\0';
			*line = ft_strsub(save, 0, i);
			save += i + 1;
			while (fd_map->fd != fd)
				fd_map = fd_map->next;
			ft_strcpy(fd_map->content, save);
			return (1);
		}
		i++;
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static t_fd_map		*fd_map;
	char				buf[BUF_SIZE + 1];
	char				*save;
	int					ret;

	if (fd < 0 || !line)
		return (-1);
	if (!fd_map)
	{
		ft_putendl("INIT");
		fd_map = new_fd_map(fd);
	}
	save = get_content(fd_map, fd);
	if (save)
	{
		if (end_line(save, line, fd_map, fd) == 1)
			return (1);
	}
	while ((ret = read(fd, &buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		save = ft_strjoin(save, buf);
		if (end_line(save, line, fd_map, fd) == 1)
			return (1);
	}
	if (ret == -1)
		return (-1);
	*line = ft_strsub(save, 0, ft_strlen(save));
	//free(save);
	return(0);
}
