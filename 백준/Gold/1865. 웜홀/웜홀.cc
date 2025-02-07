#include <iostream>
#include <vector>
#include <utility>
#include <tuple>

using namespace std;

const int INF = 987654321;

bool Bellman_ford()
{
    int N, M, W;
    cin >> N >> M >> W;

    vector<tuple<int, int, int>> Edge;

    for (int i = 0; i < M; ++i)
    {
        int s, e, t;
        cin >> s >> e >> t;
        Edge.push_back(make_tuple(s, e, t));
        Edge.push_back(make_tuple(e, s, t));
    }

    for (int i = 0; i < W; ++i)
    {
        int s, e, t;
        cin >> s >> e >> t;
        Edge.push_back(make_tuple(s, e, -t));
    }

    vector<int> dist(N + 1, INF);
    dist[1] = 0; // 시작점 1로 지정
    for (int i = 0; i < N - 1; ++i)
    {
        for (int j = 0; j < Edge.size(); ++j)
        {
            auto [From, To, Cost] = Edge[j];

            if (dist[From] + Cost < dist[To])
            {
                dist[To] = dist[From] + Cost;
            }
        }
    }

    for (int j = 0; j < Edge.size(); ++j)
    {
        auto [From, To, Cost] = Edge[j];

        if (dist[From] + Cost < dist[To])
        {
            return true;
        }
    }

    return false;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        if (Bellman_ford())
        {
            cout << "YES" << '\n';
        }
        else
        {
            cout << "NO" << '\n';
        }
    }

    return 0;
}
