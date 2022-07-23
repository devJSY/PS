#include <iostream>

int main()
{
	int n;
	int TimeBox[3] = { 300 , 60 , 10 }, CntBox[3] = {0,};

	scanf("%d", &n);

	for (int i = 0; i < 3; ++i)
	{
		CntBox[i] += n / TimeBox[i];
		n %= TimeBox[i];
	}

	if (n != 0) printf("%d", -1);
	else printf("%d %d %d", CntBox[0], CntBox[1], CntBox[2]);

	return 0;
}