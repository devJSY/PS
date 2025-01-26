#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int N, M;

// From, To
vector<pair<int, int>> SL;

const int INF = 987654321;
int visited[105];

void Dijkstra()
{
    // Count, Num;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pQ;
    pQ.push(make_pair(0, 1));
    visited[1] = 0;

    while (!pQ.empty())
    {
        auto [Count, Num] = pQ.top();
        pQ.pop();

        if (Num == 100)
        {
            cout << Count << '\n';
            break;
        }

        for (int i = 1; i <= 6; ++i)
        {
            int NewNum = Num + i;

            if (NewNum > 100)
                continue;

            for (const auto elem : SL)
            {
                if (NewNum == elem.first)
                {
                    NewNum = elem.second;
                }
            }

            if (visited[NewNum] > Count + 1)
            {
                visited[NewNum] = Count + 1;
                pQ.push(make_pair(Count + 1, NewNum));
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

    for (int i = 0; i < N + M; ++i)
    {
        int u, v;
        cin >> u >> v;
        SL.push_back(make_pair(u, v));
    }

    std::fill(visited, visited + 105, INF);

    Dijkstra();

    return 0;
}