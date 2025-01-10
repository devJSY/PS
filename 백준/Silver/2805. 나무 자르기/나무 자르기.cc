#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> arr;

bool solve(int h)
{
    long long sum = 0;
    for (int i = 0; i < arr.size(); ++i)
    {
        sum += max(0, arr[i] - h);
    }

    return sum >= M;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    arr.resize(N);

    int st = 0;
    int ed = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> arr[i];
        ed = max(ed, arr[i]);
    }

    while (st < ed)
    {
        int mid = (st + ed + 1) / 2;
        if (solve(mid))
        {
            st = mid;
        }
        else
        {
            ed = mid - 1;
        }
    }

    cout << st << '\n';

    return 0;
}