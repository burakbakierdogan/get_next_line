/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:26:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 14:45:17 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int fd1;
	fd1 = open("deneme.txt", O_RDONLY);
	char *str;
	char *str2;
	int	fd2 = open("burak.txt", O_RDONLY);
	//printf("%d\n", fd);

	int n = 10000;



		while (n--)
		{
			str = get_next_line(fd1);
			str2 = get_next_line(fd2);
			printf("%s\n %s", str,str2);
			free(str);
			free(str2);
		}
		free(str);
		free(str2);
		close (fd1);
		close (fd2);
}

