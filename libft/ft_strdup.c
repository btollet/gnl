/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 16:57:13 by btollet           #+#    #+#             */
/*   Updated: 2016/12/18 17:12:20 by benjamin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*result;

	result = (char*)malloc(sizeof(char) * (int)ft_strlen(s) + 1);
	if (!result)
		return (NULL);
	ft_strcpy(result, s);
	return (result);
}
