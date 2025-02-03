#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int N, M;
int parent[100] = {};
bool bTruth[100] = {};

int Find(int a)
{
    if (parent[a] == a)
        return a;

    return Find(parent[a]);
}

void Union(int a, int b)
{
    a = Find(a);
    b = Find(b);
    if (bTruth[a])
    {
        parent[b] = a;
        bTruth[b] = true;
    }
    else if (bTruth[b])
    {
        parent[a] = b;
        bTruth[a] = true;
    }
    else
    {
        parent[a] = b;
    }
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    for (int i = 0; i <= 50; ++i)
    {
        parent[i] = i;
    }

    cin >> N >> M;

    int T;
    cin >> T;

    while (T--)
    {
        int truth;
        cin >> truth;
        bTruth[truth] = true;
    }

    queue<vector<int>> Q;

    for (int i = 0; i < M; ++i)
    {
        int cnt;
        cin >> cnt;
        vector<int> peoples(cnt);

        int FirstPeople;
        cin >> FirstPeople;

        peoples.push_back(FirstPeople);

        for (int j = 1; j < cnt; ++j)
        {
            int people;
            cin >> people;
            peoples[j] = people;
            Union(FirstPeople, people);
        }

        Q.push(peoples);
    }

    int ret = 0;

    while (!Q.empty())
    {
        vector<int> vec = Q.front();
        Q.pop();

        bool bDirty = false;

        for (int elem : vec)
        {
            int p = Find(elem);
            if (bTruth[p])
            {
                bDirty = true;
                break;
            }
        }

        if (!bDirty)
        {
            ++ret;
        }
    }

    cout << ret << '\n';

    return 0;
}
