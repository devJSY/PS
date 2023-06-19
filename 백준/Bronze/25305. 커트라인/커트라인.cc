#include <iostream>

using namespace std;

int main()
{
	int n = 0;
	int k = 0;

	int arr[1001] = {};

	cin >> n >> k;

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	for (size_t i = 0; i < n; i++)
	{
		for (size_t j = i + 1; j < n; j++)
		{
			if (arr[i] < arr[j])
			{
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}

	cout << arr[k - 1] << endl;

	return 0;
}