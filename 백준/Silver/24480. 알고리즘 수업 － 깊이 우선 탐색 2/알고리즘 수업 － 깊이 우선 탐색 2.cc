#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int visited[100001] = {};
int idx = 1;

void DFS(vector<vector<int>>& vec, int r)
{
	visited[r] = idx;
	++idx;
	for (size_t i = 0; i < vec[r].size(); i++)
	{
		if (visited[vec[r][i]] == 0)
		{
			DFS(vec, vec[r][i]);
		}
	}
}

bool cmp(int& a, int& b)
{
	return a > b;
}

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

	int u = 0;
	int v = 0;

	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v;
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (size_t i = 1; i <= n; i++)
	{
		sort(vec[i].begin(), vec[i].end(), cmp);
	}

	DFS(vec, r);

	for (size_t i = 1; i <= n; i++)
	{
		cout << visited[i] << '\n';
	}	

	return 0;
}