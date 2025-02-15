#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> MinDP(3);
    vector<int> MaxDP(3);

    for (int i = 0; i < 3; ++i)
    {
        int num;
        cin >> num;
        MinDP[i] = MaxDP[i] = num;
    }

    for (int i = 1; i < N; ++i)
    {
        vector<int> NewMinDP(3);
        vector<int> NewMaxDP(3);

        for (int j = 0; j < 3; ++j)
        {
            int num;
            cin >> num;

            if (0 == j)
            {
                NewMinDP[j] = num + min(MinDP[0], MinDP[1]);
                NewMaxDP[j] = num + max(MaxDP[0], MaxDP[1]);
            }
            else if (2 == j)
            {
                NewMinDP[j] = num + min(MinDP[1], MinDP[2]);
                NewMaxDP[j] = num + max(MaxDP[1], MaxDP[2]);
            }
            else
            {
                NewMinDP[j] = num + min({MinDP[0], MinDP[1], MinDP[2]});
                NewMaxDP[j] = num + max({MaxDP[0], MaxDP[1], MaxDP[2]});
            }
        }

        MinDP = NewMinDP;
        MaxDP = NewMaxDP;
    }

    cout << *max_element(MaxDP.begin(), MaxDP.end()) << " ";
    cout << *min_element(MinDP.begin(), MinDP.end());

    return 0;
}
