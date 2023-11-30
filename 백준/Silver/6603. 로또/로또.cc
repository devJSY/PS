#include <bits/stdc++.h>

using namespace std;

int K;
int arr[50];
int result[10];
int ch[10];

void DFS(int L, int idx)
{
    if (L == 6)
    {
        for (size_t i = 0; i < 6; i++)
        {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }


    for (size_t i = idx; i < K; i++)
    {
        if (!ch[i])
        {
            ch[i] = true;
            result[L] = arr[i];
            DFS(L + 1, i);
            ch[i] = false;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    while (1)
    {
        cin >> K;
        if (K == 0)
            break;

        for (size_t i = 0; i < K; i++)
        {
            cin >> arr[i];
        }

        DFS(0, 0);

        cout << '\n';

        fill(arr, arr + K, 0);
    }

    return 0;
}