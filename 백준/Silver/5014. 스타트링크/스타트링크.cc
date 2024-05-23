#include <bits/stdc++.h>

using namespace std;

int F, S, G, U, D;

int arr[1000005];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> F >> S >> G >> U >> D;

    std::fill(arr, arr + F + 1, -1);

    queue<pair<int, int>> Q;

    Q.push(make_pair(0, S));
    arr[S] = 0;

    while (!Q.empty())
    {
        int cost, pos;
        tie(cost, pos) = Q.front();
        Q.pop();

        if (pos == G)
        {
            cout << cost;
            return 0;
        }

        if (0 != U && pos + U <= F && -1 == arr[pos + U])
        {
            arr[pos + U] = 1;
            Q.push(make_pair(cost + 1, pos + U));
        }

        if (0 != D && pos - D > 0 && -1 == arr[pos - D])
        {
            arr[pos - D] = 1;
            Q.push(make_pair(cost + 1, pos - D));
        }
    }

    cout << "use the stairs";

    return 0;
}
