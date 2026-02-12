#include <stdio.h>
#include "adder.h"

int main()
{
	printf("Hello, world\n");
	int x, y;
	x = 2;
	y = 2;
	printf("%d + %d = %d\n", x, y, add(x,y));
	return 0;
}
