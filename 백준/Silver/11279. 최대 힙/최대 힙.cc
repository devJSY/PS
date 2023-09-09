#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    priority_queue<int> pq;

    int n = 0;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;

        if (num == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top() << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push(num);
        }
    }
  
    return 0;
}