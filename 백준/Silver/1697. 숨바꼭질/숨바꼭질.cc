#include <iostream>
#include <queue>
#include <utility>

using namespace std;

bool visited[100001];
const int MinBound = 0;
const int MaxBound = 100000;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    queue<pair<int, int>> Q;
    Q.push(make_pair(0, N));
    visited[N] = true;

    while (!Q.empty())
    {
        auto [Depth, Num] = Q.front();
        Q.pop();

        if (Num == K)
        {
            cout << Depth;
            break;
        }

        if (Num + 1 <= MaxBound && !visited[Num + 1])
        {
            Q.push(make_pair(Depth + 1, Num + 1));
            visited[Num + 1] = true;
        }

        if (Num - 1 >= MinBound && !visited[Num - 1])
        {
            Q.push(make_pair(Depth + 1, Num - 1));
            visited[Num - 1] = true;
        }

        if (Num * 2 <= MaxBound && !visited[Num * 2])
        {
            Q.push(make_pair(Depth + 1, Num * 2));
            visited[Num * 2] = true;
        }
    }

    return 0;
}