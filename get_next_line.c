/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/07 12:25:42 by benjamin          #+#    #+#             */
/*   Updated: 2017/01/07 17:37:22 by benjamin         ###   ########.fr       */
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

int			end_line(char **line, char *file, char **Save, int fd)
{
	char *tmp;

	if (!file[0])
		return (0);
	if ((tmp = ft_strchr(file, '\n')) != NULL)
		*tmp = 0;
	*line = ft_strdup(file);
	ft_memdel((void *)&file);
	if (tmp)
		Save[fd] = ft_strdup(tmp + 1);
	else
		Save[fd] = NULL;
	tmp = NULL;
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*Save[MAX_FD];
	char			buf[BUF_SIZE + 1];
	char			*file;
	int				ret;

	if (fd < 0 || !line)
		return (-1);
	if (Save[fd] == NULL)
		file = ft_strnew(0);
	else
		return (end_line(line, Save[fd], Save, fd));
	while ((ret = read(fd, &buf, BUF_SIZE)) > 0)
	{
		buf[ret] = 0;
		file = ft_strappend(file, buf);
	}
	if (ret == -1)
		return (-1);
	return (end_line(line, file, Save, fd));
}