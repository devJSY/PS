#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> Q;

    int N;

    cin >> N;

    for (size_t i = 0; i < N * N; i++)
    {
        int x;
        cin >> x;

        Q.push(x);

        if ((int)Q.size() > N)
            Q.pop();
    }

    cout << Q.top() << '\n';

    return 0;
}