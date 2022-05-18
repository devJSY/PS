#include<iostream>

int main()
{
	int i,n,m,min = 1'000'000, max = -1'000'000;

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &m);
		
		if (m < min) min = m;
		if (m > max) max = m;
	}

	printf("%d %d", min, max);
}