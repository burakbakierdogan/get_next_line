/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/10 10:25:33 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;

	buf = malloc (BUFFER_SIZE);
	bzero(buf, BUFFER_SIZE);
	int a = 0;
	int k;
	k = BUFFER_SIZE;
	read (fd, buf + a++, 1);
	while (k--)
	{
		read(fd, buf + a++, 1);
		if (buf[a-1] == '\n')
			return (buf);
	}
	return (buf);
}
