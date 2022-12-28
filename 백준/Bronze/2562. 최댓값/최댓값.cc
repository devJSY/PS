#include <iostream>

int main()
{
	int a, Idx, max = -2147000000;	
	
	for(int i =1; i <= 9; ++i)
	{
		scanf("%d", &a);
		
		if(max < a)
		{
			max = a;
			Idx = i;
		}
	}
	
	printf("%d\n%d", max, Idx);
	
	
	return 0;
}