#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    while (T--)
    {
        multiset<int> Q;
        int k;
        cin >> k;

        for (size_t i = 0; i < k; i++)
        {
            char order;
            int Num;
            cin >> order >> Num;

            if ('I' == order)
            {
                Q.insert(Num);
            }
            else if ('D' == order && !Q.empty())
            {
                if (1 == Num)
                {
                    auto iter = prev(Q.end());
                    Q.erase(iter);
                }
                else if (-1 == Num)
                {
                    auto iter = Q.begin();
                    Q.erase(iter);
                }
            }
        }

        if (Q.empty())
        {
            cout << "EMPTY" << '\n';
        }
        else
        {
            cout << *prev(Q.end()) << " " << *Q.begin() << '\n';
        }
    }

    return 0;
}