/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/12 17:01:03 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	int		index;
	int		index2;
	int		ret;
	int		r_total;

	index = 0;
	ret = 1;
	index2 = BUFFER_SIZE;
	r_total=0;
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));

	if (index2 == 1)
	{
		ret = read(fd, (buf), 1);
		if (ret == 0 || ret == -1)
			return (NULL);
		return (buf);
	}
	while (index2--)
	{
		ret = read(fd, (buf + index++), 1);
		r_total += ret;
		if (ret == -1 || ret == 0)
			return (NULL);
		if (buf[index-1] == '\n')
			break;
	}

	str = (char *) malloc ((r_total) * sizeof (char));
	if (!str)
		return (NULL);
	ft_get_memcpy((r_total), str, buf);
	free(buf);
	return (str);
}
