#include <iostream>

int main()
{
	int arr[30] = {3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,8,8,8,8,9,9,9,10,10,10,10}, i, result = 0;
	
	char a[100];
	
	scanf("%s" , a);
	
	for(i =0; a[i] != '\0'; ++i)
	{
		int idx = a[i] - 65;
		
		result += arr[idx];
	}
	
	printf("%d", result);
	
	
	return 0;
}

