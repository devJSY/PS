#include <bits/stdc++.h>

using namespace std;

int N, M;

const int INF = 0x3f3f3f3f;

vector<pair<int, int>> adj[1005]; // 가중치, 정점
int d[1005];
int pre[1005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    std::fill(d, d + N + 1, INF);

    for (size_t i = 0; i < M; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back(make_pair(c, b));
    }

    int st, ed;
    cin >> st >> ed;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pQ;

    d[st] = 0;
    pQ.push(make_pair(0, st));

    while (!pQ.empty())
    {
        int w, v;
        tie(w, v) = pQ.top();
        pQ.pop();

        if (d[v] != w)
            continue;

        for (const auto& next : adj[v])
        {
            if (d[next.second] > next.first + d[v])
            {
                d[next.second] = next.first + d[v];
                pQ.push(make_pair(d[next.second], next.second));
                pre[next.second] = v;
            }
        }
    }

    cout << d[ed] << '\n';

    vector<int> path;
    int cur = ed;
    while (cur != st)
    {
        path.push_back(cur);
        cur = pre[cur];
    }
    path.push_back(cur);
    cout << path.size() << '\n';
    std::reverse(path.begin(), path.end());
    for (const auto& elem : path)
    {
        cout << elem << " ";
    }

    return 0;
}
