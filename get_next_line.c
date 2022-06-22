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
	int	total;
	int	index2;

	index2 = 0;
	total = 0;
	while (index)
	{
		if (cont[index--] == '/n')
			total++;
	}
	if (total)
	{
		while (cont[index2] != '\n')
			index2++;
		return (index2);
	}
	return (0);
}
int	ft_empty_cont(char *cont, char *cont2, int index)
{
	int		index2;

	index2 = 0;
	if (cont2 == NULL)
		cont2 = (char *) malloc (index + 1 * sizeof(char));
	if (!cont)
		return (NULL);
	while (index--)
	{
		cont2[index2] == cont[index2];
		index2++;
	}
	return (index2);
}
int	ft_mmove(char *dest, char *source, int index)
{
	int index2;

	index2 = index;
	while (index--)
		dest[index] = source[index];
	return (index2);
}

int	ft_nl_searhcer(char *cont, int index)
{
	char *dest;
	int total_nl;

	total_nl = ft_is_newline(cont, index);
	if (total_nl)
	{
		dest = ft_move(dest, cont, index);
	}
}



char	*get_next_line(int fd)
{
	char	buf[BUFFER_SIZE];
	static char	*cont2 = NULL;
	static int	index = 0;
	int			rret;

	rret = 0;
	if (index == 0)
	{
		rret = read (fd, buf, BUFFER_SIZE);
		if (rret == 0 || rret == -1)
			return (NULL);
	}
	if (index)
	{
		index =
	}




}
