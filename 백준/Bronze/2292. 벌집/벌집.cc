#include <iostream>


int main()
{
	int input, result = 1, subt = 6;
	
	scanf("%d", &input);

	while(input > 1)
	{
		++result;
		input -= subt;
		subt += 6;				
	}

	printf("%d", result);
	
	return 0;
}

