#include <bits/stdc++.h>

using namespace std;

int V, E;
vector<pair<int, int>> adj[10005];
bool vist[10005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> V >> E;

    for (size_t i = 0; i < E; i++)
    {
        int cost, V1, V2;
        cin >> V1 >> V2 >> cost;
        adj[V1].push_back(make_pair(cost, V2));
        adj[V2].push_back(make_pair(cost, V1));
    }

    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    vist[1] = true;
    for (const auto& pair : adj[1])
    {
        pq.push(make_tuple(pair.first, 1, pair.second));
    }

    int cnt = 0;
    int result = 0;
    while (cnt < V - 1)
    {
        int cost, V1, V2;
        tie(cost, V1, V2) = pq.top();
        pq.pop();

        if (vist[V2])
            continue;

        vist[V2] = true;
        cnt++;
        result += cost;

        for (const auto& pair : adj[V2])
        {
            if (vist[pair.second])
                continue;

            pq.push(make_tuple(pair.first, V2, pair.second));
        }
    }

    cout << result;

    return 0;
}