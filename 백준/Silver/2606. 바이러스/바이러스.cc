#include <iostream>
#include <vector>

using namespace std;

vector<int> vec[101];
bool ch[101];
int result = 0;

void DFS(int n)
{
    ch[n] = true;
    for (size_t i = 0; i < vec[n].size(); i++)
    {
        int m = vec[n][i];
        if (!ch[m])
        {
            DFS(m);
            result++;
        }
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
    DFS(1);
    cout << result << '\n';

    return 0;
}