#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    int answer = 0;

    for (size_t i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        stack<char> st;

        for (char ch : str)
        {
            if (ch == 'A')
            {
                if (!st.empty() && st.top() == 'A')
                    st.pop();
                else
                    st.push('A');
            }
            else if (ch == 'B')
            {
                if (!st.empty() && st.top() == 'B')
                    st.pop();
                else
                    st.push('B');
            }
        }

        if (st.empty())
            answer++;
    }

    cout << answer;

    return 0;
}
