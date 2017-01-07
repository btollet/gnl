/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:25:42 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/07 13:56:37 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char		*ft_strappend(char *Save, char *buf)
{
	char	*result;
	int		len;

	len = (int)ft_strlen(Save);
	if ((result = (char *)malloc(sizeof(char) * len + BUF_SIZE + 2)) == NULL)
		return (NULL);
	ft_strcpy(result, Save);
	ft_strcpy(result + len, buf);
	ft_memdel((void *)&Save);
	return (result);
}

int			end_line(char **line, char **Save, int fd)
{
	char *tmp;

	if ((tmp = ft_strchr(Save[fd], '\n')) != NULL)
	{
		*tmp = 0;
		*line = ft_strdup(Save[fd]);
		ft_memdel((void *)&Save[fd]);
		Save[fd] = ft_strdup(tmp + 1);
		tmp = NULL;
		return (1);
	}
	else
	{
		*line = Save[fd];
		Save[fd] = ft_strnew(0);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*Save[MAX_FD];
	char			buf[BUF_SIZE + 1];
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (Save[fd] == NULL)
		Save[fd] = ft_strnew(0);
	while ((ret = read(fd, &buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		Save[fd] = ft_strappend(Save[fd], buf);
	}
	if (ret == -1)
		return (-1);
	if (Save[fd][0] != 0)
		return (end_line(line, Save, fd));
	return (0);
}