/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/07/03 05:47:25 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"



int	ft_strlen(char *str)
{
	int	index;

	index = 0;
	while (str[index] != '\0')
		index++;
	return (index);
}

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

char	*ft_str_merge(char *container, char *buf)
{
	int		index;
	int		index2;
	char	*str;

	index = -1;
	index2 = 0;
	if (!container)
	{
		container = (char *) malloc (1 * sizeof(char));
		container[0] = '\0';
	}
	if (!container || !buf)
		return (NULL);
	str = (char *) malloc ((ft_strlen(buf) + ft_strlen(container) + 1) * sizeof(char));
	if (!str)
		return (NULL);
	if (container)
		while(container[++index])
			str[index] = container[index];
	while (buf[index2])
		str[index++] = buf[index++];
	str[ft_strlen(container) + ft_strlen(buf)] = '\0';
	free (container);
	return (str);
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
		container = ft_str_merge(container, buf);
	}
	free (buf);
	return (container);
}

char	ft_ret_line(char *container)
{
	int		index;
	char	*ret;

	index = 0;
	if (!container[index])
		return (NULL);
	while (container[index] && container[index] != '\n')
		index++;
	ret = (char *) malloc (sizeof(char) * (index + 2));
	if (!ret)
		return (NULL);
	index = 0;
	while (container[index] && container[index] != '\n')
	{
		ret[index] = container[index];
		index++;
	}
	if (container[index] == '\n')
	{
		ret[index] = container[index];
		index++;
	}
	ret[index] = '\0';
	return (ret);
}

char	*ft_new_contaier(char *container)
{
	int		index;
	int		index2;
	char	*str;

	index = 0;
	while (container[index] && container[index] != '\n')
		index++;
	if (!container[index])
	{
		free (container);
		return (NULL);
	}
	str = (char *) malloc (sizeof(char) * (ft_strlen(container) - index + 1));
	if (!str)
		return (NULL);
	index++;
	index2 = 0;
	while (container[index])
		str[index2++] = container[index++];
	str[index2++] = '\0';
	free(container);
	return (str);
}

char	*get_next_line(int fd)
{
	char	*ret;
	static char	*container;
	if (fd < 0 || BUFFER_SIZE < 0)
		return (0);
	container = ft_container(fd, container);
	if (!container)
		return (NULL);
	container = ft_container(fd, container);
	ret = ft_ret_line(container);
	container = ft_new_contaier(container);
	return (ret);
}
