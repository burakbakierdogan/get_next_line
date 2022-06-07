/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/07 17:03:36 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *str;
	char *ptr;
	str = (char *) malloc (BUFFER_SIZE);
	bzero(str, BUFFER_SIZE);
	int a = 0;
	while (a < BUFFER_SIZE)
	{
		if (str[a] == '\n')
			return (str);
		read (fd, str + a, 1);
		a++;
	}
	printf("burak\n");
	return (str);
}
