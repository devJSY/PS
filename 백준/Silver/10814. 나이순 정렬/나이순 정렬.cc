#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

bool compare(pair<int, string> a, pair<int, string> b)
{
	return a.first < b.first;
}

int main()
{
	int n = 0;
	cin >> n;
	vector<pair<int, string>> vec;

	for (size_t i = 0; i < n; i++)
	{
		string str;
		int num = 0;
		cin >> num >> str;
		vec.push_back(make_pair(num, str));
	}
	
	stable_sort(vec.begin(), vec.end(), compare);

	for (size_t i = 0; i < n; i++)
	{
		cout << vec[i].first << " " << vec[i].second << '\n';
	}

	return 0;
}