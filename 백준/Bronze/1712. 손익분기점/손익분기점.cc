#include<iostream>

int main(){
	
	int a,b,c,sum,sum2;
	
	scanf("%d%d%d", &a, &b ,&c);
	
	sum  = c - b;
	
	if (b >= c) 
	{
		printf("-1");
		exit(0);
	}
	
	sum2 = a / sum + 1;
	
	printf("%d", sum2);
	
	return 0;
}