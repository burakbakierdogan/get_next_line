/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:01 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/12 16:21:57 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_get_memcpy(size_t	nmemb, char *dest, char *source)
{
	size_t	index;

	index = 0;
	nmemb++;
	while (nmemb--)
	{
		dest[index] = source[index];
		index++;
	}
	return (dest);
}

/*char	*ft_get_calloc(size_t nmemb, size_t size)
{
	void	*ptr;
	size_t	i;
	int		j;

	j = 0;
	i = nmemb;
	ptr = (char *) malloc (nmemb * size);
	if (!ptr)
		return (NULL);
	while (i--)
		ptr[j++] = '\0';
	return (ptr);
}
*/
