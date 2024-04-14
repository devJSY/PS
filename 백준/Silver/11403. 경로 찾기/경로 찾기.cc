#include <bits/stdc++.h>

using namespace std;

int N;
vector<int> arr[105];
bool vist[105];
int result[105][105];

void DFS(int _Num)
{
    for (int i = 0; i < arr[_Num].size(); i++)
    {
        if (vist[arr[_Num][i]])
            continue;

        vist[arr[_Num][i]] = true;
        DFS(arr[_Num][i]);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < N; x++)
        {
            int Num;
            cin >> Num;
            if (0 < Num)
                arr[y].push_back(x);
        }
    }

    for (int i = 0; i < N; i++)
    {
        std::fill(vist, vist + N, false);
        DFS(i);

        for (size_t j = 0; j < N; j++)
        {
            result[i][j] = vist[j];
        }
    }

    for (size_t y = 0; y < N; y++)
    {
        for (size_t x = 0; x < N; x++)
        {
            cout << result[y][x] << " ";
        }
        cout << '\n';
    }

    return 0;
}