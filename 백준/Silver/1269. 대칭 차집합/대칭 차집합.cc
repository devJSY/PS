#include <iostream>
#include <set>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;
	int num = 0;

	cin >> n >> m;

	set<int> Set;

	int minus = 0;
	for (int i = 0; i < n + m; i++)
	{
		cin >> num;
		auto iter = Set.insert(num);
		if (iter.second == false) minus--;
	}

	cout << Set.size() + minus << endl;

	return 0;
}