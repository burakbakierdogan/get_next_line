#include <stdio.h>
int main(){
	char *str = "burakbakierd\nogan";
	int a =0;
	while (str[a] != '\n')
		a++;

	printf("%s, %d",str,a);
}
