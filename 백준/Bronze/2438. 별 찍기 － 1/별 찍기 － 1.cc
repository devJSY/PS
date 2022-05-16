#include <iostream>

int main()
{
	int i, T, count;

	scanf("%d", &T);

	for (i = 0; i < T; ++i)
	{
		for (count = 0; i > count; ++count)
		{
			printf("*");
		}
		printf("*\n");
	}
}