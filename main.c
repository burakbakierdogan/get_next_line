#include "get_next_line.h"

int main ()
{
	int fd;
	fd = open("deneme.txt", O_RDONLY);
	char *str;

	int n = 99;

	while (n--)
	{
		str = get_next_line(fd);
		printf("%s", str);
	}


}
