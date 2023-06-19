#include <iostream>

using namespace std;

int main()
{
	int n = 0;

	int arr[1001] = {};

	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> arr[i];
	}

	// 삽입정렬
	for (size_t i = 0; i < n; i++)
	{
		int min = arr[i];
		int idx = i;

		for (size_t j = i + 1; j < n; j++)
		{
			if (arr[j] < min)
			{
				min = arr[j];
				idx = j;
			}
		}

		int temp = arr[idx];
		arr[idx] = arr[i];
		arr[i] = temp;
	}

	for (size_t i = 0; i < n; i++)
	{
		cout << arr[i] << endl;
	}

}