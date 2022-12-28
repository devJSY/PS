#include <iostream>

int main()
{
	int i,j, T, count;

	scanf("%d", &T);

	for (i = 1; i <= T; ++i)
	{
		for (count = T - i; count > 0; --count) printf(" ");

		for (j = 0; j < i; ++j) printf("*");

		printf("\n");
	}
}