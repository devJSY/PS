#include <bits/stdc++.h>

using namespace std;

int N, M;
int X, Y;
vector<int> adj[105];
int vist[105];

int result = -1;

void DFS(int L, int n)
{
    if (n == Y)
    {
        result = L;
        return;
    }

    for (int i = 0; i < adj[n].size(); ++i)
    {
        if (vist[adj[n][i]])
            continue;

        vist[adj[n][i]] = true;
        DFS(L + 1, adj[n][i]);
        vist[adj[n][i]] = false;
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> X >> Y >> M;
    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    vist[X] = 1;
    DFS(0, X);

    cout << result;

    return 0;
}
