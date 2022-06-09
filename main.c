#include "get_next_line.h"

int main ()
{
	int fd;
	fd = open("burak.txt", O_RDONLY);
	char *str;

	int n = 5;


		str = get_next_line(fd);
		printf("%s", str);

}
