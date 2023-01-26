#include <iostream>


int main()
{
	int a,b,c;
	
	scanf("%d%d%d", &a, &b, &c);
	
	c -= b;
	
	if(c <= 0) printf("-1");
	else
	{
		int result = a / c + 1;
		printf("%d", result);		
	}


	return 0;
}

