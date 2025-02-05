#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int V;

// 간선, 비용
vector<vector<pair<int, int>>> Graph;
int Cost[100005];
bool visited[100005];

void DFS(int N)
{
    visited[N] = true;

    for (int i = 0; i < Graph[N].size(); ++i)
    {
        int v = Graph[N][i].first;
        int cost = Graph[N][i].second;

        if (visited[v])
            continue;

        Cost[v] = Cost[N] + cost;
        DFS(v);
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> V;

    Graph.resize(V + 1);

    for (int i = 0; i < V; ++i)
    {
        int u, v, cost;

        cin >> u;

        while (1)
        {
            cin >> v;

            if (v == -1)
                break;

            cin >> cost;

            Graph[u].push_back(make_pair(v, cost));
        }
    }

    // 임의의점 1으로부터 출발
    DFS(1);

    auto maxIt = std::max_element(Cost, Cost + 100005);

    // 인덱스 계산
    int maxIndex = std::distance(Cost, maxIt);

    std::fill(Cost, Cost + 100005, 0);
    std::fill(visited, visited + 100005, false);

    DFS(maxIndex);

    cout << *std::max_element(Cost, Cost + 100005) << '\n';

    return 0;
}
