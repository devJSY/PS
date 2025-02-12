#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N;
const int INF = 987654321;
vector<vector<pair<int, int>>> Tree;

int ret[2][10005];
bool visited[2][10005];

void bfs(int type, int StartIdx)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(0, StartIdx));

    while (!Q.empty())
    {
        auto [Dist, Node] = Q.front();
        Q.pop();

        ret[type][Node] = Dist;
        visited[type][Node] = true;

        for (const auto& elem : Tree[Node])
        {
            int NextNode = elem.first;
            int NextCost = elem.second;

            if (visited[type][NextNode])
                continue;

            Q.push(make_pair(Dist + NextCost, NextNode));
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    Tree.resize(N + 1);

    for (int i = 0; i < N - 1; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Tree[u].push_back(make_pair(v, w));
        Tree[v].push_back(make_pair(u, w));

        ret[0][i] = INF;
        ret[1][i] = INF;
    }

    bfs(0, 1);

    int MaxVal = 0;
    int MaxValIdx = -1;

    for (int i = 1; i <= N; ++i)
    {
        if (ret[0][i] > MaxVal)
        {
            MaxVal = ret[0][i];
            MaxValIdx = i;
        }
    }

    bfs(1, MaxValIdx);

    int result = 0;

    for (int i = 1; i <= N; ++i)
    {
        if (ret[1][i] > result)
        {
            result = ret[1][i];
        }
    }

    cout << result << '\n';

    return 0;
}
