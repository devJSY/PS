#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[32005];
int Indegrees[32005];
queue<int> Q;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        Indegrees[b]++;
    }

    for (size_t i = 1; i <= N; i++)
    {
        if (0 == Indegrees[i])
        {
            Q.push(i);
        }
    }

    while (!Q.empty())
    {
        int Num = Q.front();
        Q.pop();

        cout << Num << " ";

        for (auto Next : adj[Num])
        {
            Indegrees[Next]--;
            if (0 == Indegrees[Next])
            {
                Q.push(Next);
            }
        }
    }

    return 0;
}