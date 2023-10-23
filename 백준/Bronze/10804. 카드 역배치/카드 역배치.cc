#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> arr(21);

	for (size_t i = 1; i <= 20; i++)
	{
		arr[i] = i;
	}

	for (size_t i = 0; i < 10; i++)
	{
		int begin, end;
		cin >> begin >> end;

		reverse(arr.begin() + begin, arr.begin() + end + 1);
	}

	for (size_t i = 1; i <= 20; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

