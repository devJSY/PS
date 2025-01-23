#include <iostream>

using namespace std;

const int MAXNUM = 100005;

int parent[MAXNUM];
int cost[MAXNUM];
bool visited[MAXNUM];

int N, M, K;

int Find(int x)
{
    if (x == parent[x])
        return x;

    return parent[x] = Find(parent[x]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (cost[a] >= cost[b])
    {
        parent[a] = b;
    }
    else
    {
        parent[b] = a;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K;

    for (int i = 1; i <= N; ++i)
    {
        parent[i] = i;
        cin >> cost[i];
    }

    for (int i = 0; i < M; ++i)
    {
        int a, b;
        cin >> a >> b;
        Union(a, b);
    }

    int ret = 0;
    for (int i = 1; i <= N; ++i)
    {
        int P = Find(i);
        if (!visited[P])
        {
            ret += cost[P];
            visited[P] = true;
        }
    }

    if (ret <= K)
    {
        cout << ret << '\n';
    }
    else
    {
        cout << "Oh no" << '\n';
    }

    return 0;
}