#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;

	cin >> n >> m;

	unordered_set<string> set;

	for (size_t i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		set.insert(str);
	}

	int answer = 0;

	for (size_t i = 0; i < m; i++)
	{
		string str;
		cin >> str;

		if (set.find(str) != set.end()) answer++;
	}

	cout << answer << endl;
	
	return 0;
}