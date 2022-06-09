/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:01 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/09 16:29:15 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	ft_ncounter(int fd)
{
	int	index;

	index = 0;
	char *str;
	while (*str != '\n')
	{
		read(fd,str,1);
		index++;
	}
	return index;
}

