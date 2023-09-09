#include <iostream>
#include <queue>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> pq;

    int n = 0;
    int input = 0;
    cin >> n;
    while (n--)
    {
        cin >> input;
        if (input == 0)
        {
            if (pq.empty())
                cout << 0 << '\n';
            else
            {
                cout << pq.top().second << '\n';
                pq.pop();
            }
        }
        else
        {
            pq.push({ abs(input), input });
        }
    }
  
    return 0;
}