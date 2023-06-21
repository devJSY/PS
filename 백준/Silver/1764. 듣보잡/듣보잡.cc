#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	map<string, int> Map;

	int n = 0;
	int m = 0;

	cin >> n >> m;

	string str;

	for (size_t i = 0; i < n; i++)
	{
		cin >> str;
		Map[str]++;
	}

	int cnt = 0;

	for (size_t i = 0; i < m; i++)
	{
		cin >> str;
		Map[str]++;
		if (Map[str] == 2) cnt++;
	}

	cout << cnt << '\n';

	map<string, int>::iterator iter = Map.begin();

	for (; iter != Map.end(); iter++)
	{
		if (iter->second == 2)
		{
			cout << iter->first << '\n';
		}
	}

	return 0;
}