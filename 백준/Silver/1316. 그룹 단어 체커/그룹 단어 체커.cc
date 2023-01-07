#include <iostream>

bool IsCheck(char n[])
{
	bool flag = true;
	int i,j;
	
	for(i=0; n[i] != '\0'; ++i)
	{
		for(j = 0; j < i; ++j)
		{
			if(n[i] != n[i - 1] && n[i] == n[j])
			{
				flag = false;
			}
		}		
	}
	
	
	return flag;
}


int main()
{
	int n, i, cnt = 0;
	char a[120];
	
	scanf("%d", &n);
	
	for(i = 0; i<n; ++i)
	{
		scanf("%s", a);
				
		if(IsCheck(a))
		{
			++cnt;
		}
	}
	
	printf("%d", cnt);

	return 0;
}

