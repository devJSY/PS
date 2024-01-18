#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N;
    cin >> N;

    vector<int> Aarr(N);
    vector<int> Barr(N);

    for (size_t i = 0; i < N; i++)
        cin >> Aarr[i];

    for (size_t i = 0; i < N; i++)
        cin >> Barr[i];

    int result = 0;

    for (size_t i = 0; i < N; i++)
    {
        vector<int>::iterator Aiter = min_element(Aarr.begin(), Aarr.end());
        vector<int>::iterator Biter = max_element(Barr.begin(), Barr.end());
        result += (*Biter) * (*Aiter);
        Aarr.erase(Aiter);
        Barr.erase(Biter);
    }

    cout << result;

    return 0;
}
