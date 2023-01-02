#include <iostream>

int main()
{
	int i, j, k, n, a;
	char arr[150];
	
	scanf("%d", &n);
	
	for(i =0 ; i < n; ++i)
	{
		scanf("%d %s", &a, &arr);
		
		for(j = 0; arr[j] != '\0'; ++j)
		{
			for(k =0; k < a; ++k)
			{
				printf("%c", arr[j]);
			}
		}
		
		printf("\n");
	}

	return 0;
}

