/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/07/02 18:37:50 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	ft_is_nl(char *buf)
{
	int	index;
	int	total;

	index = 0;
	total = 0;
	while (buf[index] != '/0')
	{
		if (buf[index] == '\n')
			total++;
		index++;
	}
	return (total);
}

char	*ft_str_append(char *container, char buf)
{
	int		index;
	int		index2;
	char	*str;

	if (!container)
	{
		container = (char *) malloc (1 * sizeof(char));
		
	}
}

char	*ft_container(int fd, char *container)
{
	int		rret;
	char	*buf;

	buf = (char *) malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buf)
		return (NULL);
	rret = 1;
	while (!ft_is_nl(container) || rret != 0)
	{
		rret = read (fd, buf, BUFFER_SIZE);
		if (rret == -1)
		{
			free(buf);
			return (NULL);
		}
		buf[rret] = '\0';
		container = ft_str_append(container, buf);
	}

}





char	*get_next_line(int fd)
{
	char	*ret;
	static char	*container;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	container =



}
