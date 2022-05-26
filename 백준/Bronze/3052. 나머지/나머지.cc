#include<iostream>

int main() {
	int i, n, a[1000] = {0, }, cnt = 0, k;

	for (i = 0; i <= 9; ++i)
	{
		scanf("%d", &n);
		a[n % 42]++;
	}

	for (i = 0; i < 1000; ++i)
	{
		if (a[i] != 0) cnt++;
	}

	printf("%d", cnt);

	return 0;
}