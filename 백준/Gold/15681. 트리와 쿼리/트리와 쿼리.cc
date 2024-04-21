#include <bits/stdc++.h>

using namespace std;

int N, R, Q;
vector<int> adj[1000005];
int arrSize[1000005];

void DFS(int curNode, int parent)
{
    arrSize[curNode] = 1;

    for (auto child : adj[curNode])
    {
        if (child == parent)
            continue;

        DFS(child, curNode);
        arrSize[curNode] += arrSize[child];
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> R >> Q;

    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DFS(R, -1);

    for (size_t i = 0; i < Q; i++)
    {
        int P;
        cin >> P;

        cout << arrSize[P] << '\n';
    }

    return 0;
}