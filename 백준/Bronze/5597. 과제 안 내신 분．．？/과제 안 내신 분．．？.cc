#include <iostream>

int main()
{
	int n, a[100];
	
	for(int i =1; i <= 30; ++i)
	{
		scanf("%d", &n);
		a[n] = 1;	
	}
	
	for(int i =1; i <= 30; ++i)
	{
		if(1 != a[i])
		printf("%d\n", i);
	}	
	
	return 0;
}