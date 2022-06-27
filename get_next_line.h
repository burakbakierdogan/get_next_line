/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:04 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/13 15:09:50 by berdogan         ###   ########.fr       */
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

#ifndef CONTAINER_SIZE
# define CONTAINER_SIZE 1000000
# endif

char	*get_next_line(int fd);

int		ft_start(int fd, char *buf);
int		ft_is_nl(char *buf, int size);
int		ft_len(char *buf, int size);
void	ft_move(char *dest, char *source, int size);
char	*ft_newstr(char *buf, int size);
char	*ft_write(char *buf, int fd, int rret);





#endif
