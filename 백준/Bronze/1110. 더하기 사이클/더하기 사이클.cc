#include <iostream>

int main()
{
	int n,a,b,sum = 0,cnt = 0;
	
	scanf("%d", &n);
		
	sum = n;
	
	while(1)	
	{			
		a = sum / 10;
		b = sum % 10;
		
		sum = a+b;
		
		sum = b*10 + sum % 10;
		
		++cnt;
		
		if(n == sum)
		break;
	}
	
	printf("%d", cnt);
	
	return 0;
}