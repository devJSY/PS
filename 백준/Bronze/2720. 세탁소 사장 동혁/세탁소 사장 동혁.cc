#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
	int n, t, i ,j;

	int money[4] = { 25, 10, 5, 1 };
	int testcase[4] = { 0,0,0,0 };

	scanf("%d", &n);

	for (i = 0; i < n; ++i)
	{
		scanf("%d", &t);

		for (j = 0; j < 4; ++j)
		{
			while (money[j] <= t)
			{
				t -= money[j];
				testcase[j]++;
			}
		}

		for (j = 0; j < 4; ++j)
		{
			printf("%d ", testcase[j]);
			testcase[j] = 0;
		}
		printf("\n");
	}

	return 0;
}