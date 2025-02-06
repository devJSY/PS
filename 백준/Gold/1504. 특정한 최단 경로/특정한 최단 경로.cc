#include <iostream>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

const int INF = 987654321;

int N, E;
int u, v;

// Node, Dist
vector<vector<pair<int, int>>> Graph;

long long ret[3][805];

void Dijkstra(int StartIdx, int Step)
{
    // Node, Dist
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pQ;
    pQ.push(make_pair(StartIdx, 0));
    ret[Step][StartIdx] = 0;

    while (!pQ.empty())
    {
        auto [Node, Dist] = pQ.top();
        pQ.pop();

        for (const auto& elem : Graph[Node])
        {
            if (Dist + elem.second < ret[Step][elem.first])
            {
                ret[Step][elem.first] = Dist + elem.second;
                pQ.push(make_pair(elem.first, Dist + elem.second));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> E;

    Graph.resize(N + 1);

    for (int i = 0; i < E; ++i)
    {
        int a, b, c;
        cin >> a >> b >> c;
        Graph[a].push_back(make_pair(b, c));
        Graph[b].push_back(make_pair(a, c));
    }

    cin >> u >> v;

    // 거리값 초기화
    for (int i = 0; i < 3; ++i)
    {
        for (int j = 0; j < 805; ++j)
        {
            ret[i][j] = INF;
        }
    }

    Dijkstra(1, 0);
    Dijkstra(u, 1);
    Dijkstra(v, 2);

    long long result = INF;

    result = min(ret[0][u] + ret[1][v] + ret[2][N], ret[0][v] + ret[2][u] + ret[1][N]);

    if (result >= INF)
    {
        cout << -1 << '\n';
    }
    else
    {
        cout << result << '\n';
    }

    return 0;
}
