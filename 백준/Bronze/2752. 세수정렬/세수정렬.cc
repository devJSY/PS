#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> vec(3);

	for (size_t i = 0; i < vec.size(); i++)
	{
		cin >> vec[i];
	}

	sort(vec.begin(), vec.end());

	cout << vec[0] << " " << vec[1]  << " " << vec[2];

	return 0;
}
