#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	string str;
	cin >> str;

	int arr[100] = {};

	for (char ch : str)
	{
		arr[ch - 'a']++;
	}

	for (size_t i = 0; i <= 'z' - 'a'; i++)
	{
		cout << arr[i] << " ";
	}

	return 0;
}

