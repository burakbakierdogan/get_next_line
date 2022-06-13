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

static	char	*ft_isbuf_one(int fd, char *buf)
{
	int	ret;

	ret = 0;
	if (BUFFER_SIZE == 1)
	{
		ret = read(fd, buf, 1);
		if (ret == 0 || ret == -1)
			return (NULL);
		buf[1] = '\0';
		return (buf);
	}
	return (buf);
}

char	*get_next_line(int fd)
{
	char	*buf;
	int		index;
	int		index2;
	int		ret;
	int		r_total;

	index = 0;
	ret = 1;
	index2 = BUFFER_SIZE;
	r_total = 0;
	buf = (char *) malloc (BUFFER_SIZE + 1 * sizeof(char));
	if (BUFFER_SIZE == 1)
		return (ft_isbuf_one(fd, buf));
	while (index2--)
	{
		ret = read(fd, (buf + index++), 1);
		r_total += ret;
		if (ret == -1 || ret == 0)
			return (NULL);
		if (buf[index - 1] == '\n')
			break ;
	}
	return (ft_get_memcpy(r_total + 1, buf));
}
