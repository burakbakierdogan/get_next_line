/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:04 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/12 16:03:11 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

#ifndef BUFFER_SIZE
# define BUFFER_SIZE 10
# endif

char	*ft_get_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);
char	*ft_get_memcpy(size_t	nmemb, char *dest, char *source);





#endif
