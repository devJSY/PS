#include <bits/stdc++.h>

using namespace std;

int N, M, X;

vector<pair<int, int>> adj[2][1005];
int d[2][1005];

const int INF = 0x3f3f3f3f3f;

void Dijkstra(int idx)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

    pQ.push(make_pair(0, X));
    d[idx][X] = 0;

    while (!pQ.empty())
    {
        int W, V;
        tie(W, V) = pQ.top();
        pQ.pop();

        if (d[idx][V] != W)
            continue;

        for (const auto& elem : adj[idx][V])
        {
            if (d[idx][elem.second] > W + elem.first)
            {
                d[idx][elem.second] = W + elem.first;
                pQ.push(make_pair(d[idx][elem.second], elem.second));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M >> X;

    std::fill(d[0], d[0] + N + 1, INF);
    std::fill(d[1], d[1] + N + 1, INF);

    for (size_t i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[0][a].push_back(make_pair(c, b));
        adj[1][b].push_back(make_pair(c, a));
    }

    Dijkstra(0);
    Dijkstra(1);

    int maxValue = 0;

    for (size_t i = 1; i <= N; i++)
    {
        maxValue = std::max(maxValue, d[0][i] + d[1][i]);
    }

    cout << maxValue;

    return 0;
}
