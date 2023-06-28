#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	queue<int> Q;

	int n = 0;
	int k = 0;

	cin >> n >> k;

	for (int i = 1; i <= n; i++)
	{
		Q.push(i);
	}

	cout << '<';

	while (Q.size() != 1)
	{
		for (int i = 1; i < k; i++)
		{
			Q.push(Q.front());
			Q.pop();
		}

		cout << Q.front() << ", ";
		Q.pop();		
	}

	cout << Q.front() << '>';

	return 0;
}