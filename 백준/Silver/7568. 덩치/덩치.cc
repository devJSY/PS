#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n, x, y;

	cin >> n;

	vector<pair<pair<int, int>, int>> vec;

	for (size_t i = 0; i < n; i++)
	{
		cin >> x >> y;
		vec.push_back(make_pair(make_pair(x, y), 1));		
	}

	for (size_t i = 0; i < vec.size(); i++)
	{
		for (size_t j = 0; j < vec.size(); j++)
		{
			if (i == j)
				continue;

			if (vec[i].first.first < vec[j].first.first
				&& vec[i].first.second < vec[j].first.second)
			{
				vec[i].second++;
			}
		}

		cout << vec[i].second << " ";
	}

	return 0;
}

