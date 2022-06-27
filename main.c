/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berdogan <berdogan@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/12 16:26:40 by berdogan          #+#    #+#             */
/*   Updated: 2022/06/13 15:24:39 by berdogan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int main ()
{
	int fd;
	fd = open("burak.txt", O_RDONLY);
	char *str;

	int n = 12;



		str = get_next_line(fd);
		printf("%s", str);

}

