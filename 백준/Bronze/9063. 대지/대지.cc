#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n = 0;
    cin >> n;

    vector<pair<int, int>> vec;


    int MaxX = -2147000000;
    int MaxY = -2147000000;
    int MinX = 2147000000;
    int MinY = 2147000000;

    int y = 0;
    int x = 0;

    for (int i = 0; i < n; i++)
    {
        cin >> y >> x;

        vec.push_back(make_pair(y, x));

        if (y > MaxY) MaxY = y;
        if (x > MaxX) MaxX = x;
        if (y < MinY) MinY = y;
        if (x < MinX) MinX = x;
    }

    cout << (MaxY - MinY) * (MaxX - MinX) << endl;

    return 0;
}
