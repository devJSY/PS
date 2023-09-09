#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec[1001];
bool ch[1001];
bool ch2[1001];

int n = 0;
int m = 0;
int v = 0;

void DFS(int num)
{
    ch[num] = true;

    cout << num << ' ';

    for (size_t i = 0; i < vec[num].size(); i++)
    {
        if(!ch[vec[num][i]])
            DFS(vec[num][i]);
    }
}

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);


    cin >> n >> m >> v;

    for (int i = 0; i < m; i++)
    {
        int a = 0;
        int b = 0;
        cin >> a >> b;
        vec[a].push_back(b);
        vec[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        sort(vec[i].begin(), vec[i].end());
    }

    DFS(v);
    cout << '\n';

    queue<int> Q;

    Q.push(v);
    ch2[v] = true;

    while (!Q.empty())
    {
        int num = Q.front();
        cout << num << " ";
        Q.pop();

        for (int i = 0; i < vec[num].size(); i++)
        {            
            if (!ch2[vec[num][i]])
            {
                Q.push(vec[num][i]);
                ch2[vec[num][i]] = true;
            }
        }
    }
  
    return 0;
}