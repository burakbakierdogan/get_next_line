#include <stdio.h>

int main()
{
	char *ptr[1024];
	ptr[10] = "aurak";
	printf("%d\n", *(ptr[10]));


}
