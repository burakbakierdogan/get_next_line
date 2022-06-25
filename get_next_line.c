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

char	*ft_nl(int fd, int t_ret, char buf)
{
	int r_ret;

	r_ret = 0;
	while (ft_is_nl(buf, r_ret) == 0)
	{
		r_ret = read(fd, buf + t_ret, BUFFERSIZE);
		t_ret += r_ret;
		if (r_ret == 0 || r_ret == -1)
			break;
	}
	if (r_ret != -1 || r_ret != 0 && t_ret)
		{

		}
}
int	ft_t_ret_zero(int fd, char *buf)
{
	int	t_ret;

	t_ret = 0;
	t_ret = read(fd, buf, BUFFERSIZE);
	if (r_ret == -1 || r_ret == 0)
		return (0);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	static int	t_ret = 0;
	char		*str;

	if (!buf)
		buf = (char *) malloc (CONTAINER_SIZE * sizeof(char));
	if (!buf)
		return (NULL);
	if (!t_ret)
		t_ret = ft_t_ret_zero(fd, buf);
	if (!t_ret)
		return (NULL);
	if (ft_is_nl(buf, t_ret))
	{
		t_ret = 0;
		str = 0;

	}
	else
	{
		t_ret = 0;
		str = 0;
		
	}
	return (str);
}
