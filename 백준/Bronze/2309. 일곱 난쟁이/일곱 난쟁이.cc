#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);

	vector<int> vec(9);
	int sum = 0;
	for (size_t i = 0; i < 9; i++)
	{
		cin >> vec[i];
		sum += vec[i];
	}

	sort(vec.begin(), vec.end());
		
	for (size_t i = 0; i < 8; i++)
	{
		for (size_t j = i + 1; j < 9; j++)
		{
			if (sum - (vec[i] + vec[j]) == 100)
			{
				for (size_t k = 0; k < vec.size(); k++)
				{
					if (k == i || k == j) continue;
					cout << vec[k] << '\n';
				}
				return 0;
			}
		}
	}

	return 0;
}
