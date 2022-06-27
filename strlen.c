#include <stdio.h>
#include <unistd.h>

int ft_strlen(char *buf)
{
	int index = 0;
	while (buf[index] != '\n')
		index++;
	return (index);
}

int main ()
{
	char str[] = {'b','u', 'r', 'a', 'k', '\n'};
	int index = ft_strlen(str);
	write(1, &str[index], 1);
}
