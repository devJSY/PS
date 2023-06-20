#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;

	set<int> set;

	for (size_t i = 0; i < n; i++)
	{
		int num = 0;
		cin >> num;
		set.insert(num);
	}

	int m = 0;
	cin >> m;

	for (size_t i = 0; i < m; i++)
	{
		int num = 0;
		cin >> num;

		if (set.find(num) == set.end())
		{
			cout << 0 << " ";
		}
		else
		{
			cout << 1 << " ";
		}
	}
	
	return 0;
}