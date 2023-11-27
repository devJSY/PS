#include <bits/stdc++.h>

using namespace std;

int N, M;
int result[10];
int arr[10];
int Isvisited[10];

void DFS(int L, int idx)
{
    if (L == M)
    {
        for (size_t i = 0; i < M; i++)
        {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (size_t i = idx; i < N; i++)
    {
        if (!Isvisited[i])
        {
            Isvisited[i] = true;
            result[L] = arr[i];
            DFS(L + 1, i);
            Isvisited[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        cin >> arr[i];
    }

    sort(arr, arr + N);

    DFS(0, 0);

    return 0;
}