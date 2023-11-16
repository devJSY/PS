#include <bits/stdc++.h>
using namespace std;

int n;
int cnt[3]; //-1, 0, 1로 채워진 종이 갯수

bool check(vector<vector<int>> &vec, int x, int y, int n)
{
    for (int i = x; i < x + n; i++)
        for (int j = y; j < y + n; j++)
            if (vec[x][y] != vec[i][j])
                return false;
    return true;
}

void recursion(vector<vector<int>>& vec, int x, int y, int z)
{
    if (check(vec, x, y, z))
    {
        cnt[vec[x][y] + 1] += 1;
        return;
    }
    int n = z / 3;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 3; j++)
            recursion(vec, x + i * n, y + j * n, n);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    vector<vector<int>> vec(n, vector<int>(n));

    for (size_t y = 0; y < n; y++)
    {
        for (size_t x = 0; x < n; x++)
        {
            cin >> vec[y][x];
        }
    }

    recursion(vec, 0, 0, n);

    for (int i = 0; i < 3; i++)
        cout << cnt[i] << "\n";
}
