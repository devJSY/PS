#include <iostream>

int main()
{
	int i;
	char a[200] = {};
	char b[120] = {};	
	
	scanf("%s", &b);
	
	for(i = 97; i < 123; ++i)
	{
		a[i] = -1;		
	}
	
	for(i = 0; b[i] != '\0'; ++i)
	{
		if(a[b[i]] == -1) a[b[i]] = i;		
	}
	
	for(i = 97; i < 123; ++i)
	{
		if(a[i] != -1)
		{
			printf("%d ", a[i]);
		}		
		else
		{
			printf("-1 ");
		}
	}	

	
	return 0;
}

