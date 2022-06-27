#include <stdio.h>
#include <stdlib.h>


void ft_3(char *buf)
{
	buf[2] = '\0';
}
void ft_2(char *buf)
{
	buf[1] = 'b';
	ft_3(buf);
}

void	ft_1(char *buf)
{
	buf[0] = 'a';
	ft_2(buf);
}
int main ()
{
	char *buf;

	buf = (char *) malloc (5);
	ft_1(buf);
	printf("%s", buf);
}
