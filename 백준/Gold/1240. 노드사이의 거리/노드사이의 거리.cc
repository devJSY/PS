#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<pair<int, int>> adj[1005];
bool vist[1005];

int BFS(int st, int ed)
{
    std::fill(vist, vist + 1003, 0);

    queue<pair<int, int>> Q;
    Q.push(make_pair(st, 0));
    vist[st] = true;

    int result = 0;

    while (!Q.empty())
    {
        auto P = Q.front();
        Q.pop();

        if (P.first == ed)
        {
            result = P.second;
            break;
        }

        for (const auto& iter : adj[P.first])
        {
            if (vist[iter.first])
                continue;

            vist[iter.first] = true;
            Q.push(make_pair(iter.first, P.second + iter.second));
        }
    }

    return result;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < N - 1; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(v, w));
        adj[v].push_back(make_pair(u, w));
    }

    for (size_t i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        cout << BFS(u, v) << '\n';
    }

    return 0;
}