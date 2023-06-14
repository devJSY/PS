#include <iostream>
#include <vector>

using namespace std;

int main()
{
	vector<int> vec;
	int n = 0;	

	while (1)
	{
		cin >> n;
		int idx = 0;
		int sum = 0;

		if (n == -1) break;

		for (int i = 1; i < n; i++)
		{
			if (n % i == 0)
			{
				vec.push_back(i);
				sum += i;
			}
		}

		if (sum == n)
		{
			cout << n << " = ";
			int i = 0;
			for (i = 0; i < vec.size() - 1; i++)
			{
				cout << vec[i] << " + ";
			}
			cout << vec[i] << endl;
		}
		else
		{
			cout << n << " is NOT perfect." << endl;
		}

		vec.clear();
	}

    return 0;
}
