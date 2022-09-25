/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 14:29:04 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 04:43:03 by berdogan         ###   ########.fr       */
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

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100000000
# endif

typedef	struct s_get
{
	int		status;// read function return value.
	char	*str;// the string to be returned
	char	*rest;//rest of the string after the newline
}	t_gnl;



char	*get_next_line(int fd);
int	ft_lenn(char *str);
int	ft_is_nl(char *str);
char	*ft_append(char *str1, char *str2);
char	*ft_move_rest(char *rest, char *to_free);
t_gnl	ft_seperate(char *str, int j);

#endif
