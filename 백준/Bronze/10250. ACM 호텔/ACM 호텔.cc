#include <iostream>

int main() 
{
	int t;
	int h,w,n;
	int y,x;
	int result;
	
	scanf("%d", &t);
	
	for(int i=0; i < t; ++i)
	{
		scanf("%d%d%d", &h, &w, &n);
		
		y = n % h;
		
		if(y == 0)
		{
			y = h;
			x = n /h;		
		}	
		else
		{
			x = n /h +1;	
		}
	
		result = y * 100 + x;	
		
		printf("%d\n", result);
	}
	

	
		
	return 0;

}