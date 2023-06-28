#include <iostream>
#include <queue>
#include <string>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;

	int n = 0;
	cin >> n;

	string str;

	for (int i = 0; i < n; i++)
	{
		cin >> str;

		if (str == "push")
		{
			int num = 0;
			cin >> num;
			Q.push(num);
		}
		else if (str == "pop")
		{
			if (Q.empty()) cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
				Q.pop();
			}
		}
		else if (str == "size")
		{
			cout << Q.size() << '\n';
		}
		else if (str == "empty")
		{
			if (Q.empty()) cout << 1 << '\n';
			else  cout << 0 << '\n';
		}
		else if (str == "front")
		{
			if (Q.empty()) cout << -1 << '\n';
			else
			{
				cout << Q.front() << '\n';
			}
		}
		else if (str == "back")
		{
			if (Q.empty()) cout << -1 << '\n';
			else
			{
				cout << Q.back() << '\n';
			}
		}
	}

	return 0;
}