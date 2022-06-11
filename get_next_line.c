/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/11 23:21:38 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char	*buf;
	char	*str;
	int		index;
	int		index2;

	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if(!buf)
		return (NULL);
	index = 0;
	index2 = BUFFER_SIZE;
	if (index2 == 1)
	{
		read(fd, (buf), 1);
		return (buf);
	}
	while (index2 > 0)
	{
		read(fd, (buf + index++), 1);
		index2--;
		if (buf[index-1] == '\n')
			break;
	}
	str = (char *) malloc ((BUFFER_SIZE) * sizeof (char));
	if (!str)
		return (NULL);
	ft_gmemcpy((BUFFER_SIZE - index2), str, buf);
	free(buf);
	return (str);
}
