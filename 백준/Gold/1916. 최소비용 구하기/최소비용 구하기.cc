#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

int N, M;
int st, ed;

vector<vector<pair<int, int>>> Graph;
vector<long long> ret;
const int INF = 987654321;

void Dijkstra()
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pQ;
    pQ.push(make_pair(0, st));
    ret[st] = 0;

    while (!pQ.empty())
    {
        auto [cost, Node] = pQ.top();
        pQ.pop();

        if (Node == ed)
            break;

        for (const auto& elem : Graph[Node])
        {
            if (elem.second + cost < ret[elem.first])
            {
                ret[elem.first] = elem.second + cost;
                pQ.push(make_pair(elem.second + cost, elem.first));
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    Graph.resize(N + 1);
    ret.resize(N + 1, INF);

    for (int i = 0; i < M; ++i)
    {
        int u, v, w;
        cin >> u >> v >> w;
        Graph[u].push_back(make_pair(v, w));
    }

    cin >> st >> ed;

    Dijkstra();

    cout << ret[ed] << '\n';

    return 0;
}
