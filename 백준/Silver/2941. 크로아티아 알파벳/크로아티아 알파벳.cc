#include <iostream>

int main()
{
	int result = 0,i;
	char a[120];
	
	scanf("%s", a);
	
	
	for(i = 0; a[i] !='\0'; ++i)
	{
		if(a[i] == 'c' && a[i + 1] == '=')
		{
			++result;
			++i;
		}
		else if(a[i] == 'c' && a[i + 1] == '-')
		{
			++result;
			++i;
		}
		else if(a[i] == 'd' && a[i + 1] == 'z' && a[i + 2] == '=')
		{
			++result;
			i += 2;
		}
		else if(a[i] == 'd' && a[i + 1] == '-')
		{
			++result;
			++i;

		}
		else if(a[i] == 'l' && a[i + 1] == 'j')
		{
			++result;
			++i;
		}
		else if(a[i] == 'n' && a[i + 1] == 'j')
		{
			++result;
			++i;
		}
		else if(a[i] == 's' && a[i + 1] == '=')
		{
			++result;
			++i;
		}
		else if(a[i] == 'z' && a[i + 1] == '=')
		{
			++result;
			++i;
		}
		else
		{
			++result;		
		}		
	}
	
	printf("%d", result);
	
	
	return 0;
}

