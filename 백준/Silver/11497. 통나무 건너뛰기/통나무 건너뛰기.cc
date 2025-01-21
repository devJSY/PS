
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int solve(const vector<int>& SortedVec)
{
    int Prev2 = SortedVec[0];
    int Prev1 = SortedVec[1];

    int ret = abs(Prev2 - Prev1);

    for (int i = 2; i < SortedVec.size(); ++i)
    {
        ret = max(ret, abs(Prev2 - SortedVec[i]));

        Prev2 = Prev1;
        Prev1 = SortedVec[i];
    }

    ret = max(ret, abs(Prev2 - Prev1));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        int N;
        cin >> N;
        vector<int> vec(N);

        for (int i = 0; i < N; ++i)
        {
            cin >> vec[i];
        }

        sort(vec.rbegin(), vec.rend());

        cout << solve(vec) << '\n';
    }

    return 0;
}
