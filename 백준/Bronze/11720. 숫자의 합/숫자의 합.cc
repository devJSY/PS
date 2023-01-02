#include <iostream>

int main()
{
	int n, i, sum = 0;
	char a[150] = {}; 
	
	scanf("%d", &n);
	
	scanf("%s", &a);
	
	for(i =0; a[i] != '\0'; ++i)
	{
		sum += a[i] - 48;
	}
	
	printf("%d", sum);
	
	return 0;
}