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
	cin >> n;

	map<string, string, greater<string>> Map;

	string name;
	string access;

	for (size_t i = 0; i < n; i++)
	{
		cin >> name >> access;
		if (Map.find(name) != Map.end())
		{
			Map.erase(name);
		}
		else
		{
			Map.insert({name, access});
		}
	}

	for (auto iter : Map) {
		cout << iter.first << '\n';
	}

	return 0;
}