#include <stdio.h>
#include <stdlib.h>


char	*ft_deneme(char *source)
{
	static char cont1[1000000];

	static int index = 0;
	int index2 = 0;
	static int k = 0;

	while (index2 < 10)
			cont1[index++] = source[index2++];
	return (&cont1[k++]);
}

int main()
{
	char *str = "burak";
	int n = 10;
	int k = 0;
	while (n--)
		printf("%s\n",ft_deneme(str));

}
