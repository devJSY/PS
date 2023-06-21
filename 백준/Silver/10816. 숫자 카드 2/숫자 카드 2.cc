#include <iostream>
#include <unordered_map>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	unordered_map<int, int> Map;

	int num = 0;

	for (size_t i = 0; i < n; i++)
	{
		cin >> num;
		Map[num]++;
	}

	int m = 0;
	cin >> m;

	for (int i = 0; i < m; i++)
	{
		cin >> num;
		cout << Map[num] << " ";
	}

	return 0;
}