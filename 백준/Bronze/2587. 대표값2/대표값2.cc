#include <iostream>

using namespace std;

int main()
{
	int arr[10] = {};
	int sum = 0;
	for (size_t i = 0; i < 5; i++)
	{
		cin >> arr[i];
		sum += arr[i];
	}

	int i = 9;
	int j = 0;

	for (i = 1; i < 5; i++)
	{
		int temp = arr[i];
		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > temp)
			{
				arr[j + 1] = arr[j];
			}
			else break;
		}

		arr[j + 1] = temp;
	}


	cout << sum / 5 << endl;
	cout << arr[2] << endl;

	return 0;
}