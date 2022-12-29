#include <iostream>
#include <vector>

using namespace std;

int selfnum(int n)
{
	int sum = 0;

	sum += n;
	
	while(1)
	{
		if(n <= 0)
		{
			break;
		}
		
		sum += n % 10;
		
		n = n / 10;				
	}	

	return sum;
}

int main()
{
	int a[12000] = {};
	
	for(int i =0; i<= 10000; ++i)
	{
		a[selfnum(i)] = 1;
	}
	
		
	for(int i = 0; i<= 10000; ++i)
	{
		if(a[i] != 1)
		{
			printf("%d\n", i);
		}		
	}	
	
	return 0;
}