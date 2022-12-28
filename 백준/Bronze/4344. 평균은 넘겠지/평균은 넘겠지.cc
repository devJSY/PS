#include <iostream>

using namespace std;

int main()
{
	int i, j, c, n, aver, a[1000], cnt;
	double result;
	
	scanf("%d", &c);
	
	for(i = 0; i< c; ++i)
	{
		scanf("%d", &n);
		aver = 0;
		cnt = 0;
		result = 0;
		
		for(j = 0; j <n; ++j)
		{
			scanf("%d", &a[j]);
			aver += a[j];
		}
		
		aver = aver / n;
		
		for(j = 0; j <n; ++j)
		{
			if(a[j] > aver)
			{
				++cnt;
			}
		
			a[j] = 0;
		}
		
		result = 100 / (double)n;
		
		printf("%.3lf%\n", result * cnt);
				
	}
	
	return 0;
}