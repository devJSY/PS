#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> vec(7);
	vector<int> vec2;
	int sum = 0;

	for (size_t i = 0; i < vec.size(); i++)
	{
		cin >> vec[i];
		if (vec[i] % 2 != 0) 
		{
			vec2.push_back(vec[i]);
			sum += vec[i];
		}
	}

	if (vec2.empty())
		cout << -1;
	else
	{
		cout << sum << '\n';
		cout << *min_element(vec2.begin(), vec2.end());
	}

	return 0;
}
