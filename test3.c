#include <stdio.h>

int main()
{
	char *ptr[1024][2];
	ptr[10][0] = "burak";
	printf("%c\n", ptr[10][0][0]);


}
