#include <iostream>
#include <queue>

using namespace std;

int N;
int Hash[15] = {};

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;

    queue<int> Q;
    int type = 0;
    int ret = 0;
    while (N--)
    {
        int num;
        cin >> num;

        Q.push(num);

        if (0 == Hash[num]++)
        {
            ++type;
        }

        while (type > 2)
        {
            int front = Q.front();
            Q.pop();
            Hash[front]--;
            if (0 == Hash[front])
            {
                --type;
            }
        }

        ret = max(ret, (int)Q.size());
    }

    cout << ret << '\n';

    return 0;
}
