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

	for (int i = 1; i <= n; i++)
	{
		Q.push(i);
	}

	while (Q.size() != 1)
	{
		Q.pop();
		Q.push(Q.front());
		Q.pop();
	}

	cout << Q.front() << '\n';


	return 0;
}