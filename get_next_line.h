/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ccorcy <ccorcy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/09 15:00:52 by ccorcy            #+#    #+#             */
/*   Updated: 2016/12/09 15:20:05 by ccorcy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUF_SIZE 10000

# include "libft/libft.h"
# include <stdlib.h>
# include <fcntl.h>

typedef struct			s_fd_map
{
	int					fd;
	char				*content;
	struct s_fd_map		*next;
}						t_fd_map;

int						get_next_line(const int fd, char **line);

#endif
