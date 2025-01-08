#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    unordered_set<string> hash;

    for (int i = 0; i < N; ++i)
    {
        string str;
        cin >> str;
        hash.insert(str);
    }

    vector<string> result;

    for (int i = 0; i < M; ++i)
    {
        string str;
        cin >> str;
        if (hash.find(str) != hash.end())
        {
            result.push_back(str);
        }
    }

    sort(result.begin(), result.end());
    cout << result.size() << '\n';
    for (const auto& elem : result)
    {
        cout << elem << '\n';
    }

    return 0;
}