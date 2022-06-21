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


char	*ft_container(char *buf, int rrret)
{
	char		*ctn;
	static	int	index;

	index = 0;
}


char	*ft_body_func(int fd)
{
	char	*buf;
	int		rret;

	rret = 0;
	buf = (char *) malloc (BUFFER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	rret = read (fd, buf, BUFFER_SIZE);
	if (rret == 0 || rret == -1)
		return (NULL);
	return (buf);
}

char	*get_next_line(int fd)
{

}
