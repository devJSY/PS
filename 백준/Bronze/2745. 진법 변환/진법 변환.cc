#include <iostream>

using namespace std;

int main()
{
	int result = 0;

	int b = 0;
	char N[50] = {};

	cin >> N >> b;

	for (int i = 0; N[i] != '\0'; i++) 
	{
		if (N[i] >= '0' && N[i] <= '9') 
		{
			result = result * b + (N[i] - '0');
		}
		else
			result = result * b + (N[i] - 'A' + 10);
	}

	cout << result << endl;
	

    return 0;
}
