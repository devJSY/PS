#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int V, E, K;

// 노드, 비용
vector<vector<pair<int, int>>> Graph;

const int INF = 987654321;

int ret[20005];

void Dijkstar()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pQ;
    pQ.push(make_pair(0, K));
    ret[K] = 0;

    while (!pQ.empty())
    {
        auto [Dist, Node] = pQ.top();
        pQ.pop();

        for (const auto& elem : Graph[Node])
        {
            if (Dist + elem.second < ret[elem.first])
            {
                ret[elem.first] = Dist + elem.second;
                pQ.push(make_pair(Dist + elem.second, elem.first));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V >> E >> K;

    Graph.resize(V + 1);
    for (int i = 0; i <= V; ++i)
    {
        ret[i] = INF;
    }

    for (int i = 0; i < E; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back(make_pair(v, w));
    }

    Dijkstar();

    for (int i = 1; i <= V; ++i)
    {
        if (ret[i] == INF)
        {
            cout << "INF" << '\n';
        }
        else
        {
            cout << ret[i] << '\n';
        }
    }

    return 0;
}
