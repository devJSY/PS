#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int n, t, i, j, k, count = 0;
	double ave, result = 0;

	scanf("%d", &n);

	vector <int> a(1000);

	for (i = 0; i < n; ++i)
	{
		ave = 0;
		count = 0;

		scanf("%d", &t);
		for (j = 0; j < t; ++j)
		{
			scanf("%d", &a[j]);
			ave += a[j];
		}

		ave /= t;

		for (k = 0; k < t; ++k)
		{
			if (ave < a[k]) count++;
		}
		
		result = (100 / float(k)) * count;
		
		printf("%.3lf%\n", result);
	}

	return 0;
}


