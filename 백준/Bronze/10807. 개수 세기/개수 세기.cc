#include <iostream>

int main()
{
	int n, a[100] = {}, v, cnt = 0;

	scanf("%d", &n);
	
	for(int i = 0; i < n; ++i)
	{
		scanf("%d", &a[i]);
	}
	
	scanf("%d", &v);
	
	for(int i = 0; i < n; ++i)
	{
		if(a[i]==v)
		{
			++cnt;
		}
	}
	
	printf("%d", cnt);
	
	return 0;
}