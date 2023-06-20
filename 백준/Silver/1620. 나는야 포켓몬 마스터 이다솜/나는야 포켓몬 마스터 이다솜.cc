#include <iostream>
#include <map>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;
	cin >> n >> m;

	map<string, int> Map1;
	map<int, string> Map2;

	string name;

	for (size_t i = 1; i <= n; i++)
	{
		cin >> name;
		Map1[name] = i;
		Map2[i] = name;
	}

	for (size_t i = 0; i < m; i++)
	{
		cin >> name;
		
		if (Map1.find(name) != Map1.end())
		{
			cout << Map1[name] << '\n';
		}
		else
		{
			int num = std::stoi(name);

			cout << Map2[num] << '\n';
		}

	}

	return 0;
}