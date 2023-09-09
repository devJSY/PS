#include <iostream>
#include <stack>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    stack<int> st;

    int n = 0;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int input = 0;
        cin >> input;

        if (input == 1)
        {
            int num = 0;
            cin >> num;
            st.push(num);
        }
        else if (input == 2)
        {
            if (st.empty())
            {
                cout << -1 << '\n';
            }
            else
            {
                cout << st.top() << '\n';
                st.pop();
            }
        }
        else if (input == 3)
            cout << st.size() << '\n';
        else if (input == 4)
        {
            if (st.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (input == 5)
        {
            if (st.empty())            
                cout << -1 << '\n';            
            else            
                cout << st.top() << '\n';            
        }
    }

    return 0;
}