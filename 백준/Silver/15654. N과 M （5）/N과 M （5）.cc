#include <bits/stdc++.h>

using namespace std;

int N, M;
int arr[10];
int result[10];
int Isvisited[10];

void DFS(int L)
{
    if (L == M)
    {
        for (size_t i = 0; i < L; i++)
        {
            cout << result[i] << " ";
        }
        cout << '\n';
        return;
    }

    for (size_t i = 0; i < N; i++)
    {
        if (!Isvisited[i])
        {
            Isvisited[i] = true;
            result[L] = arr[i];
            DFS(L + 1);
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

    sort(arr, arr+N);

    DFS(0);  

    return 0;
}