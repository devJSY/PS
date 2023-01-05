#include <iostream>

int reverse(int n)
{
	int one = n % 10, ten = (n / 10) % 10, hun = n/ 100;
	
	return (one * 100 )+ (ten * 10) + hun;	
}

int main()
{
	int a,b;
	
	scanf("%d %d", &a ,&b);

	if(reverse(a) > reverse(b))
	{
		printf("%d", reverse(a));
	}
	else
	{
	printf("%d", reverse(b));
	}
	
	return 0;
}

