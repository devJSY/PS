#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, M;

    cin >> N >> M;

    vector<int> A(N);
    vector<int> B(M);

    for (size_t i = 0; i < N; i++)
    {
        cin >> A[i];
    }

    for (size_t i = 0; i < M; i++)
    {
        cin >> B[i];
    }

    int pivotA = 0;
    int pivotB = 0;

    vector<int> result(N + M);
    int idx = 0;

    while (1)
    {
        if (pivotA >= N || pivotB >= M)
            break;

        if (A[pivotA] <= B[pivotB])
            result[idx++] = A[pivotA++];
        else
            result[idx++] = B[pivotB++];
    }

    while (pivotA < N)
    {
        result[idx++] = A[pivotA++];
    }
    while (pivotB < M)
    {
        result[idx++] = B[pivotB++];
    }

    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}