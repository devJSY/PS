#include <bits/stdc++.h>

using namespace std;

int N, K;

bool vist[2000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> K;

    queue<pair<int, int>> Q;
    Q.push(make_pair(0, N));
    vist[N] = 1;

    while (!Q.empty())
    {
        int V, Num;
        tie(V, Num) = Q.front();
        Q.pop();

        if (Num == K)
        {
            cout << V;
            break;
        }

        if (Num * 2 <= 100000 && !vist[Num * 2])
        {
            vist[Num * 2] = 1;
            Q.push(make_pair(V + 1, Num * 2));
        }

        if (Num + 1 <= 100000 && !vist[Num + 1])
        {
            vist[Num + 1] = 1;
            Q.push(make_pair(V + 1, Num + 1));
        }

        if (Num - 1 >= 0 && !vist[Num - 1])
        {
            vist[Num - 1] = 1;
            Q.push(make_pair(V + 1, Num - 1));
        }
    }

    return 0;
}
