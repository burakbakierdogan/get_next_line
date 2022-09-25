/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/25 14:04:44 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 14:04:44 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_get
{
	int		status;
	char	*str;
	char	*rest;
}	t_gnl;

char	*get_next_line(int fd);
int		ft_lenn(char *str);
int		ft_is_nl(char *str);
char	*ft_append(char *str1, char *str2);
char	*ft_move_rest(char *rest, char *to_free);
t_gnl	ft_seperate(char *str, int j);

#endif
