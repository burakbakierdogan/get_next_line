#include <stdio.h>
struct var{
	int p;
	int r;
};

int main ()
{
	struct var ab = {44,89};
	struct var cd = {44, 90};
	printf("%d %d\n", ab.p, ab.r);
}
