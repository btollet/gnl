/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/06 18:20:35 by benjamin          #+#    #+#             */
/*   Updated: 2016/12/07 09:25:55 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	end_line(char *ret, char **line)
{
	int i;

	i = 0;
	while (ret[i])
	{
		if (ret[i] == '\n')
		{
			ret[i] = '\0';
			line[0] = ret;
			return (1);
		}
		i++;
	}
	return (0);
}

int get_next_line(const int fd, char **line)
{
	static int	call_nb = 0;
	int			ret;
	char		*buf;
	char		*save;

	buf = ft_strnew(BUFF_SIZE);
	save = ft_strnew(BUFF_SIZE);
	if (fd < 0 || !line)
		return (-1);
	while ((ret = read(fd, buf, BUFF_SIZE)) > 0)
	{
		buf[ret] = '\0';
		save = ft_strjoin(save, buf);
		if (end_line(save, line) == 1)
		{
			call_nb ++;
			return (1);
		}
	}
	ft_putstr("NON\n");
	line[0] = save;
	call_nb ++;
	return (0);
}
