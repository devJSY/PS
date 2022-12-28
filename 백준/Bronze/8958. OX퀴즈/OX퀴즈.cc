#include <iostream>

using namespace std;

int main()
{
	int i,j,n, sum, result;
	char a[100];
	
	scanf("%d", &n);
	
	for(i = 0; i<n; ++i)
	{
		cin >> a;
		
		sum = 0;
		result = 0;
		
		for(j = 0; a[j] != '\0'; ++j)
		{
			if(a[j] == 'O')
			{
				++sum;
				result += sum;
			}
			else
			{
				sum = 0;
			}			
		}
		
		printf("%d\n", result);
	}
	
	
	return 0;
}