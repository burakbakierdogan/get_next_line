/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:26:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/25 05:26:20 by berdogan         ###   ########.fr       */
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

	int n = 100;



		while (n--)
		{
			str = get_next_line(fd1);
			str2 = get_next_line(fd2);
			printf("birinci %s -- ikinci %s\n", str, str2);
		}

}

