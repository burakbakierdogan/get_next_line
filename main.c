/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:26:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/09/23 02:03:54 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int fd;
	fd = open("burak.txt", O_RDONLY);
	char *str;
	printf("%d\n", fd);

	int n = 3;



		while (n--)
		{
			str = get_next_line(fd);
			printf("%s", str);
		}

}

