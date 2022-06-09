/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/09 17:27:56 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	void *buf;

	buf = malloc (BUFFER_SIZE);
	bzero(buf, BUFFER_SIZE);
	int a = 0;
	int k;
	k = 0;
	while (buf[a-1] != '\n')
		read (fd, buf + a + BUFFER_SIZE, BUFFER_SIZE);
	return ((char *)buf);
}
