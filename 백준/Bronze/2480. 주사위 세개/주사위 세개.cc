#include <iostream>

int main()
{
	int A, B, C;

	scanf("%d%d%d", &A, &B, &C);

	int most = (A > B ? (A > C ? A : C) : (B > C ? B : C));

	if ((A == B) && (B == C))
	{
		printf("%d", 10000 + (A * 1000));
	}
	else if ((A == B) || (B == C) || (A == C))
	{
		if (A == B)
			printf("%d", 1000 + (A * 100));
		else
			printf("%d", 1000 + (C * 100));
	}
	else
		printf("%d", most * 100);


	return 0;
}