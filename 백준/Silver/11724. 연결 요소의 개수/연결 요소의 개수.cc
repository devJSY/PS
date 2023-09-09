#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[1001];
bool ch[1001];

void DFS(int n)
{
    ch[n] = true;

    for (size_t i = 0; i < vec[n].size(); i++)
    {
        if (!ch[vec[n][i]])
            DFS(vec[n][i]);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    int n = 0;
    int m = 0;

    cin >> n >> m;

    for (size_t i = 0; i < m; i++)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    int result = 0;

    for (size_t i = 1; i <= n; i++)
    {
        if (!ch[i])
        {
            result++;
            DFS(i);
        }
    }
   
    cout << result << '\n';

    return 0;
}