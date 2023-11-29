#include <bits/stdc++.h>

using namespace std;

int N, M;

int arr[10];
int ch[10];
int result[10];

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

    int temp = 0;
    for (size_t i = idx; i < N; i++)
    {
        if (!ch[i] && temp != arr[i])
        {
            ch[i] = true;
            result[L] = arr[i];
            temp = arr[i];
            DFS(L + 1, i);
            ch[i] = false;
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