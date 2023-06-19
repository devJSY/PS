#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b)
{
	if (a.second == b.second)
	{
		return a.first < b.first;
	}
	else return a.second < b.second;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	vector<pair<int, int >> vec(n);

	for (size_t i = 0; i < n; i++)
	{
		int x = 0;
		int y = 0;
		cin >> x >> y;
		vec[i].first = x;
		vec[i].second = y;
	}

	sort(vec.begin(), vec.end(), compare);

	for (size_t i = 0; i < n; i++)
	{
		cout << vec[i].first << " " << vec[i].second << "\n";
	}

	return 0;
}