#include <iostream>
#include <cstring>
#include <vector>

using namespace std;

int ch[101] = {};
int diff = 2147000000;
int answer = 0;

void DFS(int L, vector<int>& vec, int sum, int m)
{
    if (L == 3)
    {
        if (sum > m) return;
        if (abs(sum - m) < diff)
        {
            answer = sum;
            diff = abs(sum - m);
        }
        return;
    }
    else
    {
        for (size_t i = L; i < vec.size(); i++)
        {
            if (ch[i] == 0)
            {
                ch[i] = 1;
                DFS(L + 1, vec, sum + vec[i], m);
                ch[i] = 0;
            }    
        }
    }
}


int main() 
{
    int n = 0;
    int m = 0;

    vector<int> arr;

    cin >> n >> m;

    for (size_t i = 0; i < n; i++)
    {
        int num = 0;
        cin >> num;
        arr.push_back(num);
    }

    DFS(0, arr, 0, m);

    cout << answer << endl;
   
    return 0;
}
