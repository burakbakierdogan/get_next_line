/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:01 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/13 15:09:17 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_start(int fd, char *buf)
{
	int	rret;

	rret = 0;
	rret = read(fd, buf, BUFFER_SIZE);
	if (rret == -1 || rret == 0)
		return (0);
}

int	ft_is_nl(char *buf, int size)
{
	int	index;

	index = 0;
	while (size >= 0)
	{
		if (buf[size] == '\n')
			index++;
		size--;
	}
	return (index);
}

int	ft_len(char *buf, int size)
{
	int	index;

	index = 0;
	while (buf[index] != '\n' && index < size)
		index++;
	if (buf[index] == '\n')
		index++;
	return (index);
}

void	ft_move(char *dest, char *source, int size)
{
	int		index;
	char	*temp;

	index = 0;
	temp = (char *) malloc ((size + 1) * sizeof(char));
	while (index < size)
	{
		temp[index] = source[index];
		index++;
	}
	index = 0;
	while (index < size)
	{
		dest[index] = temp[index];
		index++;
	}
	free (temp);
}

char	*ft_newstr(char *buf, int size)
{
	int		len;
	int		index;
	char	*str;

	index = 0;
	len = ft_len(buf, size);
	str = (char *) malloc ((len + 1) * sizeof(char));
	if (!str)
		return (NULL);
	while (index < len)
	{
		str[index]= buf[index];
		index++;
	}
	str[index] = '\0';
	ft_move(buf, buf + len, size - len);
	return (str);
}

char	*ft_write(char *buf, int fd, int rret)
{
	int		index;
	char	*str;

	index = 0;
	while (ft_is_nl(buf, rret) == 0)
	{
		index = read (fd, buf + rret, BUFFER_SIZE);
		rret += index;
		if (index == 0)
			break;
		if (index == -1)
		{
			rret++;
			break;
		}
	}
	if (ft_is_nl(buf, rret) == 0)
	{
		str = NULL;
		buf[rret + 1] = '\0';
	}
	else
		str = ft_newstr(buf, rret);
	return (str);
}
