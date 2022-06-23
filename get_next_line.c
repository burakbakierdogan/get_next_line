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

int	ft_is_nline(char *buf, int t_read)
{
	int	total;

	total = 0;
	while (t_read)
	{
		if (buf[t_read--] == '\n')
			total++;
	}
	return (total);
}

int	ft_move(char *buf, char *str, int t_read)
{
	int	index;

	index = 0;
	if (t_read == 0)
		return (0);
	str = (char *) malloc ((t_read + 1) * sizeof(char));
	if (!str)
		return (0);
	while (t_read && buf[index] != '\n')
	{
		str[index] = buf[index];
		index++;
		t_read--;
	}

	if (t_read != 0)
	{
		str[index++] = '\n';
		str[index] = '\0';
	}
	if (t_read == 0)
		str[index] = '\0';
	return (t_read);
}

int	ft_mmove(char *buf, int t_read, int f_t_read)
{
	int total;

	total = t_read;
	while (t_read)
	{
		buf[t_read] = buf[f_t_read];
		t_read--;
		f_t_read--;
	}
	return (total);
}

int	ft_no_nline(char *buf, char *str, int t_read, int fd)
{
	int	r_read;
	int	f_t_read;

	r_read = 0;
	f_t_read = t_read;
	while (ft_is_nline(buf, t_read) == 0)
	{
		r_read = read (fd, buf + t_read, BUFFER_SIZE);
		t_read += r_read;
		if (r_read == 0 || r_read == -1)
			break;
	}
	t_read = ft_move(buf, str, t_read);
	if (t_read == 0)
	{
		free(buf);
		buf = NULL;
		return (0);
	}
	if (t_read)
		t_read = ft_mmove(buf, t_read, f_t_read);
	return (t_read);
}

char	*get_next_line(int fd)
{
	static char	*buf = NULL;
	char		*str;
	int			r_read = 0;
	static int	t_read = 0;

	if (t_read == 0)
	{
		buf = (char *) malloc (CONTAINER_SIZE * sizeof (char));
		if (!buf)
			return (NULL);
		r_read = read (fd, buf, BUFFER_SIZE);
		t_read += r_read;
		if (r_read == -1 || r_read == 0)
			return (NULL);
	}
	if (t_read)
	{

		if (ft_is_nline(buf, t_read) == 0)
			t_read = ft_no_nline(buf, str, t_read, fd);
		else if (ft_is_nline(buf, t_read))
		{
			int f_t_read = t_read;
			t_read = ft_move(buf, str, t_read);
			if (t_read == 0)
			{
				free(buf);
				buf = NULL;
				return (0);
			}
			if (t_read)
			t_read = ft_mmove(buf, t_read, f_t_read);
		}
	}
	return (str);
}
