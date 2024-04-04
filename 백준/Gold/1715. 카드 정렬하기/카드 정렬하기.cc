#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    priority_queue<int, vector<int>, greater<int>> Q;

    int N;

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        int x;
        cin >> x;
        Q.push(x);
    }

    int result = 0;

    while (1)
    {
        if (Q.size() == 1)
            break;

        int a = Q.top();
        Q.pop();
        int b = Q.top();
        Q.pop();

        result += a + b;

        Q.push(a + b);
    }

    cout << result << '\n';

    return 0;
}