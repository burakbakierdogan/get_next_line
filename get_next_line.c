/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/13 15:20:33 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"




char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	static int	rret = 0;
	char		*str;

	if (!buf)
		buf = (char *) malloc (CONTAINER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (!rret)
		rret = ft_start(fd, buf);
	if (!rret)
		return (NULL);
	if (ft_is_nl(buf, rret))
	{
		str = ft_newstr(buf, rret);
		rret -= ft_len(buf);
	}
	else
	{
		str = ft_write(buf, fd, rret);
		if (!str)
			return (buf);
		rret = ft_len(buf);
	}
	return (str);
}
