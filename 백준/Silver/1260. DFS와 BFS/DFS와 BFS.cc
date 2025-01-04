#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, V;
vector<vector<int>> Graph;
vector<bool> visited;

void dfs(int V)
{
    cout << V << " ";
    visited[V] = true;
    for (int next : Graph[V])
    {
        if (!visited[next])
        {
            dfs(next);
        }
    }
}

void bfs(int V)
{
    queue<int> Q;
    Q.push(V);
    visited[V] = true;

    while (!Q.empty())
    {
        int nextV = Q.front();
        Q.pop();
        cout << nextV << " ";

        for (int next : Graph[nextV])
        {
            if (!visited[next])
            {
                Q.push(next);
                visited[next] = true;
            }
        }
    }
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    Graph.resize(N + 1);
    visited.resize(N + 1, false);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        sort(Graph[i].begin(), Graph[i].end());
    }

    dfs(V);
    visited.assign(N + 1, false);
    cout << '\n';
    bfs(V);

    return 0;
}