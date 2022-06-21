#include <stdio.h>
#include <stdlib.h>

char	*ft_deneme(char const *ptr)
{
	static char *str;


	static int n = 0;
	if (n == 0)
		str = (char *) calloc (50,1);
	int i = 0;
	while (i < 4)
	{
		str[n] = ptr[i];
		i++;
		n++;
	}
	printf("%d\n", n);
	return (str);
}

int main()
{
	char const ptr[5] = {'b','u', 'r','a','k'};
	int n = 2;
	while (n--)
		printf("%s\n",ft_deneme(ptr));
}
