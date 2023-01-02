#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int result = 0;

int Hansu(int n)
{	
	if(n < 100)
	{
		++result;
	}
	else
	{
		int one, ten, hun;
		
		one = n % 10;
		ten = (n % 100) / 10;
		hun = n / 100;
		
		if(ten - one == hun - ten)
		{
			++result;
		}		
	}


	return 0;
}

int main()
{
	int n;
	
	scanf("%d", &n);
	
	for(int i = 1; i <= n; ++i)
	{
		Hansu(i);
	}

	printf("%d", result);
	
	return 0;
}