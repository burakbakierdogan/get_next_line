# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <unistd.h>
# include <string.h>

int	ft_len(char *buf)
{
	int	index;

	index = 0;
	while (buf[index] != '\n')
		index++;
	return (index);
}

int main ()
{
		int fd;
	fd = open("burak.txt", O_RDONLY);
	char *buf;

	buf = malloc (300);
	read (fd, buf, 8);
	int t = ft_len(buf);
	//printf("%d\n", t);

	printf("%s", buf + t);

}
