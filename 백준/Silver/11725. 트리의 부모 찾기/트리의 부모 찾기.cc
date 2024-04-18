#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> adj[100005];
int p[100005];

void DFS(int _Num)
{
    for (int i = 0; i < adj[_Num].size(); i++)
    {
        if (p[adj[_Num][i]])
            continue;

        p[adj[_Num][i]] = _Num;
        DFS(adj[_Num][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N -1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(1);

    for (size_t i = 2; i <= N; i++)
    {
        cout << p[i] << '\n';
    }

    return 0;
}