#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

unordered_map<string, int> HashMap;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        HashMap.clear();

        int n;
        cin >> n;
        for (int i = 0; i < n; ++i)
        {
            string Name, Type;
            cin >> Name >> Type;
            ++HashMap[Type];
        }

        int result = 1;
        for (const auto& iter : HashMap)
        {
            result *= iter.second + 1;
        }

        cout << result - 1 << '\n';
    }

    return 0;
}