#include <stdio.h>
#include <stdlib.h>

char	*ft_deneme(char *source)
{
	char *str;
	static int	x = 0;
	printf("%p\n", &str);


	str = (char *) malloc (20);
	printf("%p\n",str);

	int n = 0;

	while (n < 4)
	{
		str[x] = source[n];
		n++;
		x++;

	}


	return (str);

}

int main ()
{
	char *str = "burak";
	ft_deneme("kekekekfek");
	printf("%s\n", ft_deneme(str));
}
