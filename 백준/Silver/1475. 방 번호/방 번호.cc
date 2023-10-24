#include <bits/stdc++.h>

using namespace std;


int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n;

	int arr[9] = {};

	while (n != 0)
	{
		int idx = n % 10;
		if (idx == 9) idx = 6;
		arr[idx]++;
		n /= 10;
	}

	int result = 0;

	while (1)
	{
		for (size_t i = 0; i < 9; i++)
		{
			arr[i]--;
		}
		arr[6]--;


		bool flag = false;
		// 체크
		for (size_t i = 0; i < 9; i++)
		{
			if (arr[i] > 0)
			{
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			cout << ++result;
			break;
		}
		else
		{
			result++;
		}
	}

	return 0;
}

