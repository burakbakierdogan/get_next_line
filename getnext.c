#include "get_next_line.h"

char	*get_next_line(int fd)
{
	char *buf;

	buf = malloc (BUFFER_SIZE);
	bzero(buf, BUFFER_SIZE);
	int a = 0;
	int k;
	k = BUFFER_SIZE;
	while (k--)
	{
		read(fd, buf + a++, 1);
		if (buf[a-1] == '\n')
			return (buf);
	}
	return (buf);
}
