#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;
int main()
{
	int n, i, j, cnt, result;
	char a[80];
	
	scanf("%d\n", &n);
	
	for(i=0; i < n; i++)
	{	
		cin >> a;
		result = 0;
		cnt = 0;
		for (j = 0; a[j] != '\0'; ++j)
		{
			if (a[j] == 'O') cnt++;
			else cnt = 0;
			
			result += cnt;
		}
		printf("%d\n", result);
	}

	return 0;
}
