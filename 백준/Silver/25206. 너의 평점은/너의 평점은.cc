#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	char str[51] = {};
	double f = 0;
	char ch1 = 0;
	char ch2 = 0;

	double sum = 0;
	double cnt = 0;

	for (size_t i = 0; i < 20; i++)
	{
		cin >> str >> f >> ch1;

		if (ch1 == 'P')
		{
			continue;
		}

		if (ch1 == 'F')
		{
			cnt += f;
			continue;
		}

		double num = 0;

		cin >> ch2;

		if (ch1 == 'A')
		{	
			num = 4;
			if (ch2 == '+') num += 0.5;
		}
		else if (ch1 == 'B')
		{
			num = 3;
			if (ch2 == '+') num += 0.5;
		}
		else if (ch1 == 'C')
		{
			num = 2;
			if (ch2 == '+') num += 0.5;
		}
		else if (ch1 == 'D')
		{
			num = 1;
			if (ch2 == '+') num += 0.5;
		}

		sum += f * num;
		cnt += f;
	}
	
	if (sum == 0)
	{
		printf("%.6f", float(0));
	}
	else
	{
		printf("%.6f", sum / cnt);
	}
	

    return 0;
}
