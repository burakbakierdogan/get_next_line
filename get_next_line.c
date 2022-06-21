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


int	ft_is_newline(char *cont, int index)
{
	int total;

	total = 0;
	while (index)
	{
		if (cont[index--] == '/n')
			total++;
	}
	return (total);
}

char	*ft_new_line_ret(char *cont, int index)
{

}
char	*get_next_line(int fd)
{
	char		*cont;
	static int	index = 0;
	int index2;

	index2 = 0;
	if (index == 0)
	{
		cont = (char *) malloc (CONTAINER_SIZE * sizeof(char));
		if (!cont)
			return (NULL);
		index = read(fd, cont, BUFFER_SIZE);
		if (index == 0 || index == -1)
			return (NULL);
	}
	if (index)
	{
		while (ft_is_newline(cont, index) == 0)
			index += (fd, cont + index, BUFFER_SIZE);
			if ()
	}


}
