#include <stdio.h>

int	ft_static()
{
	static int	a =  0;
	a++;
	return (a);
}

int	main()
{
	int n = 20;
	while (n--)
	printf("%d\n", ft_static());
}
