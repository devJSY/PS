#include<iostream>

int main()
{
	int i, n, count=0, max = 0, maxcount = 0;

	for (i = 0; i < 9; ++i)
	{
		scanf("%d", &n);
		++count;

		if (max < n)
		{
			max = n;
			maxcount = count;
		}
	}

	printf("%d\n", max);
	printf("%d\n", maxcount);

	return 0;
}