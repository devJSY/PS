#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int N, M, K;

vector<pair<int, int>> adj[20005]; // 가중치, 간선
int d[20005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> K;

    std::fill(d, d + N + 1, INF);

    for (size_t i = 0; i < M; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ; // 가중치, 간선

    pQ.push(make_pair(0, K));
    d[K] = 0;

    while (!pQ.empty())
    {
        int w, v;
        tie(w, v) = pQ.top();
        pQ.pop();

        if (d[v] != w)
            continue;

        for (const auto& elem : adj[v])
        {
            if (d[elem.second] > w + elem.first)
            {
                d[elem.second] = w + elem.first;
                pQ.push(make_pair(w + elem.first, elem.second));
            }
        }
    }

    for (size_t i = 1; i <= N; i++)
    {
        if (d[i] == INF)
            cout << "INF" << '\n';
        else
            cout << d[i] << '\n';
    }

    return 0;
}