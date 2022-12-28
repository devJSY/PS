#include <iostream>

int main()
{
	int i, T, sum = 0;

	scanf("%d", &T);

	for (i = 1; i <= T; ++i)
	{
		sum += i;
	}

	printf("%d", sum);
	return 0;
}