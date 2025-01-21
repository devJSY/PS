
#include <iostream>
#include <vector>
#include <tuple>

using namespace std;

int N, M, K;

vector<vector<int>> adj;
vector<int> cost;
vector<bool> visited;

int DFS(int Student)
{
    int MinCost = cost[Student];

    for (int next : adj[Student])
    {
        if (visited[next])
            continue;

        visited[next] = true;
        MinCost = min(MinCost, DFS(next));
    }

    return MinCost;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    adj.resize(N + 1);
    cost.resize(N + 1);
    visited.resize(N + 1);

    for (int i = 1; i <= N; ++i)
    {
        cin >> cost[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    // 그룹, 그룹 비용
    int TotalCost = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (!visited[i])
        {
            visited[i] = true;
            TotalCost += DFS(i);
        }
    }

    if (TotalCost <= K)
    {
        cout << TotalCost << '\n';
    }
    else
    {
        cout << "Oh no" << '\n';
    }

    return 0;
}
