#include <iostream>

using namespace std;

int main()
{
	int arr1[101] = {};
	int n = 0;
	int m = 0;
	cin >> n >> m;

	for (int i = 0; i < 101; ++i)
	{
		arr1[i] = i;
	}

	int a = 0;
	int b = 0;
	int temp = 0;

	for (int i = 0; i < m; ++i)
	{
		cin >> a >> b;
		temp = arr1[a];
		arr1[a] = arr1[b];
		arr1[b] = temp;
	}

	for (int i = 1; i <= n; ++i)
	{
		cout << arr1[i] << " ";
	}
	

	return 0;
}


