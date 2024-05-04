#include <bits/stdc++.h>

using namespace std;

int N;

tuple<int, int, int> Edge[1000005];
int parent[1005];

int GetParent(int InNum)
{
    if (parent[InNum] == InNum)
    {
        return InNum;
    }

    return parent[InNum] = GetParent(parent[InNum]);
}

int Union(int a, int b)
{
    a = GetParent(a);
    b = GetParent(b);

    if (a == b)
    {
        return false;
    }
    else if (a < b)
    {
        parent[b] = a;
    }
    else
    {
        parent[a] = b;
    }

    return true;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (size_t i = 1; i <= 1000; i++)
    {
        parent[i] = i;
    }

    cin >> N;

    int idx = 0;
    for (size_t y = 1; y <= N; y++)
    {
        for (size_t x = 1; x <= N; x++)
        {
            int cost;
            cin >> cost;
            if (0 == cost)
                continue;
            Edge[idx++] = make_tuple(cost, y, x);
        }
    }

    sort(Edge, Edge + idx);

    int cnt = 0;
    long long result = 0;
    for (size_t i = 0; i < idx; i++)
    {
        int cost, a, b;
        tie(cost, a, b) = Edge[i];

        if (!Union(a, b))
            continue;

        result += cost;
        cnt++;

        if (cnt == N - 1)
            break;
    }

    cout << result;

    return 0;
}