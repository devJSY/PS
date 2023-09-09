#include <iostream>
#include <deque>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    deque<int> Deque;
        
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
            Deque.push_front(num);
        }
        else if (input == 2)
        {
            int num = 0;
            cin >> num;
            Deque.push_back(num);
        }
        else if (input == 3)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.front() << '\n';
                Deque.pop_front();
            }
        }
        else if (input == 4)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.back() << '\n';
                Deque.pop_back();
            }
        }
        else if (input == 5)
        {
            cout << Deque.size() << '\n';
        }
        else if (input == 6)
        {
            if (Deque.empty())
                cout << 1 << '\n';
            else
                cout << 0 << '\n';
        }
        else if (input == 7)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.front() << '\n';
            }
        }
        else if (input == 8)
        {
            if (Deque.empty())
                cout << -1 << '\n';
            else
            {
                cout << Deque.back() << '\n';
            }
        }
    } 

    return 0;
}