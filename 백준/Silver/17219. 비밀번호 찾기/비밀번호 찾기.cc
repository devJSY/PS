#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    unordered_map<string, string> Map;

    int N, M;

    cin >> N >> M;

    for (size_t i = 0; i < N; i++)
    {
        string Address, Password;
        cin >> Address >> Password;
        Map[Address] = Password;
    }

    for (size_t i = 0; i < M; i++)
    {
        string Address;
        cin >> Address;
        cout << Map[Address] << '\n';
    }

    return 0;
}