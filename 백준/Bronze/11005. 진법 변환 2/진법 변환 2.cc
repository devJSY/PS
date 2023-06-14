#include <iostream>
#include <cstring>

using namespace std;

int main()
{
	int b = 0;
	int n = 0;
	char arr[50] = {};
	char answer[50] = {};

	cin >> n >> b;

	int idx = 0;

	while (n > 0)
	{
		int num = n % b;
		if (num >= 0 && num <= 9) num += 48;
		else if (num >= 10 && num <= 35) num += 55;

		arr[idx++] = (char)num;
		n /= b;
	}

	arr[idx] = '\0';
	idx = 0;
	int len = strlen(arr) - 1;
	for (int i = len; i >= 0; i--)
	{
		answer[idx++] = arr[i];
	}

	cout << answer << endl;
	

    return 0;
}
