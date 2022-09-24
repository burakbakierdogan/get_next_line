
/*
char	*ft_return()
{
	char	ptr[5][1000000];
	char *str = "biral";
	ptr[0] = str;


}
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
//a FiRSt LiTTlE

void	ft_write(char *str)
{
	str[2] = 'c';
	printf("%s\n", str);
}
int main(int ac, char *argv[])
{
	//argv[1][0] = 'a';
	printf("%s\n", argv[1]);
	ft_write(argv[1]);
}
