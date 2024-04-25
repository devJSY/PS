#include <bits/stdc++.h>

using namespace std;

int N, M;
vector<int> adj[1005];
int Indegrees[1005];
queue<int> Q;
vector<int> result;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < M; i++)
    {
        int singerNum;
        cin >> singerNum;

        int prev;
        for (size_t j = 0; j < singerNum; j++)
        {
            int next;
            cin >> next;
            if (j != 0)
            {
                adj[prev].push_back(next);
                Indegrees[next]++;
            }
            prev = next;
        }
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
        result.push_back(Num);

        for (auto next : adj[Num])
        {
            Indegrees[next]--;
            if (0 == Indegrees[next])
            {
                Q.push(next);
            }
        }
    }

    if (result.size() != N)
    {
        cout << 0 << '\n';
    }
    else
    {
        for (auto num : result)
        {
            cout << num << '\n';
        }
    }

    return 0;
}