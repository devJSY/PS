#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    list<char> List;

    auto cursor = List.begin();

    int n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        string str = " ";
        cin >> str;

        for (auto ch : str)
        {
            if (ch == '<')
            {
                if (cursor != List.begin())
                {
                    --cursor;
                }
            }
            else if (ch == '>')
            {
                if (cursor != List.end())
                {
                    ++cursor;
                }
            }
            else if (ch == '-')
            {
                if (cursor != List.begin())
                {
                    --cursor;
                    cursor = List.erase(cursor);
                }
            }
            else
            {
                List.insert(cursor, ch);
            }
        }

        for (auto it : List)
        {
            cout << it;
        }
        cout << '\n';

        List.clear();
        cursor = List.begin();
    }

    return 0;
}
