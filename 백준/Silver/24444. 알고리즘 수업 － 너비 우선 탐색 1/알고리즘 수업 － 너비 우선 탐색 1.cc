#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;
int visited[1000001] = {};
static int idx = 1;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	int m = 0;
	int r = 0;

	cin >> n >> m >> r;

	vector<vector<int>> vec(n + 1);

	queue<int> Q;

	int u = 0;
	int v = 0;

	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (size_t i = 0; i < n; i++)
	{
		sort(vec[i].begin(), vec[i].end());
	}
	
	Q.push(r);	
	visited[r] = idx++;

	while (!Q.empty())
	{
		int num = Q.front();
		Q.pop();

		for (size_t i = 0; i < vec[num].size(); i++)
		{
			if (visited[vec[num][i]] == 0)
			{
				Q.push(vec[num][i]);
				visited[vec[num][i]] = idx++;
			}
		}
	}

	for (size_t i = 1; i <= n; i++)
	{
		cout << visited[i] << '\n';
	}


	return 0;
}