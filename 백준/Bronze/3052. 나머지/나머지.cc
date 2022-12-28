#include <iostream>

int main()
{
	int a[100] = {}, n, i, cnt = 0;
	
	for(i =0; i < 10;++i)
	{
		scanf("%d", &n);
		
		++a[n % 42];
	}
	
	for(i =0; i < 100;++i)
	{
		if(a[i] != 0) ++cnt;
	}
	
	printf("%d", cnt);
	
	
	return 0;
}