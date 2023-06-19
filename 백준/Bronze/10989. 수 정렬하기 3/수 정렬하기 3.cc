#include <iostream>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	int arr[10001] = {};

	int num = 0;
	for (size_t i = 0; i < n; i++)
	{
		cin >> num;
		arr[num]++;
	}

	for (int i = 0; i < 10001; i++)
		for (int j = 0; j < arr[i]; j++)
			cout << i << '\n';

	return 0;
}