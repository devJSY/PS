#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int arrSum[100];
int N, M;
vector<vector<int>> Graph;

int bfs(int start)
{
    int ret = 0;

    queue<pair<int, int>> Q;
    vector<bool> visited(N + 1, false);

    Q.push(make_pair(start, 0));
    visited[start] = true;

    while (!Q.empty())
    {
        auto [Num, Step] = Q.front();
        Q.pop();

        ret += Step;

        for (const auto& next : Graph[Num])
        {
            if (!visited[next])
            {
                Q.push(make_pair(next, Step + 1));
                visited[next] = true;
            }
        }
    }

    return ret;
}

int main()
{
    ios_base ::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Graph.resize(N + 1);

    for (int i = 0; i < M; ++i)
    {
        int u, v;
        cin >> u >> v;
        Graph[u].push_back(v);
        Graph[v].push_back(u);
    }

    for (int i = 1; i <= N; ++i)
    {
        arrSum[i] = bfs(i);
    }

    int MinNum = 987654321;
    int MinIdx = -1;
    for (int i = N; i >= 1; --i)
    {
        if (MinNum >= arrSum[i])
        {
            MinNum = arrSum[i];
            MinIdx = i;
        }
    }

    cout << MinIdx << '\n';

    return 0;
}