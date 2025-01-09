#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    vector<pair<int, int>> vec;

    cin >> N;

    for (int i = 0; i < N; ++i)
    {
        int x, y;
        cin >> x >> y;
        vec.push_back(make_pair(x, y));
    }

    sort(vec.begin(), vec.end());

    int st = vec[0].first;
    int ed = vec[0].second;
    int ret = 1;
    for (int i = 1; i < vec.size(); ++i)
    {
        // 이어지는 경우에 ed가 더 짧은 경우 갱신
        if (vec[i].second < ed)
        {
            st = vec[i].first;
            ed = vec[i].second;
        }
        // 다른 회의 시간인 경우
        else if (vec[i].first >= ed)
        {
            st = vec[i].first;
            ed = vec[i].second;
            ret++;
        }
    }

    cout << ret << '\n';

    return 0;
}