#include <bits/stdc++.h>

using namespace std;

int N, E;

vector<pair<int, int>> adj[805];
long long d[3][805];

int V1, V2;

const int INF = 0x3f3f3f3f;

void Dijkstra(int st, int idx)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

    pQ.push(make_pair(0, st));
    d[idx][st] = 0;

    while (!pQ.empty())
    {
        int cost, V;
        tie(cost, V) = pQ.top();
        pQ.pop();

        if (d[idx][V] != cost)
            continue;

        for (const auto& elem : adj[V])
        {
            if (d[idx][elem.second] > cost + elem.first)
            {
                d[idx][elem.second] = cost + elem.first;
                pQ.push(make_pair(d[idx][elem.second], elem.second));
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> E;

    for (size_t i = 0; i < 3; i++)
    {
        std::fill(d[i], d[i] + N + 1, INF);
    }

    for (size_t i = 0; i < E; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
        adj[b].push_back(make_pair(c, a));
    }

    cin >> V1 >> V2;

    Dijkstra(1, 0);
    Dijkstra(V1, 1);
    Dijkstra(V2, 2);

    long long result = std::min(d[0][V1] + d[1][V2] + d[2][N], d[0][V2] + d[2][V1] + d[1][N]);

    if (INF <= result)
        cout << -1;
    else
        cout << result;

    return 0;
}

