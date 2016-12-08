/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:20:35 by benjamin          #+#    #+#             */
/*   Updated: 2016/12/08 17:00:50 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line(char *ret, char **line, char *before)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\n')
		{
			ret[i] = '\0';
			line[0] = ret;
			ret += i + 1;
			before = ft_strcpy(before, ret);
			return (1);
		}
		i++;
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static char *before = NULL;
	int			ret;
	char		*buf;
	char		*save;

	buf = ft_strnew(BUFF_SIZE);
	save = ft_strnew(BUFF_SIZE);
	if (before != NULL)
	{
		save = ft_strcpy(save, before);
		if (end_line(save, line, before) == 1)
			return (1);
	}
	before = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line)
	{
		before = NULL;
		return (-1);
	}
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (end_line(save, line, before) == 1)
			return (1);
	}
	line[0] = save;
	before = NULL;
	return (0);
}
