/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:28:57 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 05:47:51 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static	t_gnl	ft_read(char *rest, int fd)
{
	t_gnl	ret_val;
	char	*new;
	int		i;

	i = 2;
	new = (char *) malloc(sizeof(char) * (BUFFER_SIZE + 1));
	while (i > 0)
	{
		i = read(fd, new, BUFFER_SIZE);
		new[i] = '\0';
		if (ft_is_nl(new))
		{
			rest = ft_append(rest, new);
			break ;
		}
		else
		rest = ft_append(rest, new);
	}
	free(new);
	ret_val = ft_seperate (rest, i);
	return (ret_val);
}

char	*get_next_line(int fd)
{
	static char	*container[1024];
	t_gnl		ret_vals;

	if (fd <= 0 || BUFFER_SIZE <= 0)
		return (NULL);
	if (ft_is_nl (container[fd]))
	{
		ret_vals = ft_seperate (container[fd], 1);
		container[fd] = ret_vals.rest;
		return (ret_vals.str);
	}
	else
	{
		ret_vals = ft_read (container[fd], fd);
		container[fd] = ret_vals.rest;
	}
	if (!ret_vals.rest && ret_vals.status <= 0)
		return (NULL);
	if (ret_vals.str)
		return (ret_vals.str);
	else if (ret_vals.rest && ret_vals.status <= 0)
		return (ret_vals.rest);
	else
		return (NULL);
}
