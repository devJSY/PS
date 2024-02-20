#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> Aarr;
    vector<int> Barr;

    int Acnt, Bcnt;
    cin >> Acnt >> Bcnt;

    for (size_t i = 0; i < Acnt; i++)
    {
        int num;
        cin >> num;
        Aarr.push_back(num);
    }

    for (size_t i = 0; i < Bcnt; i++)
    {
        int num;
        cin >> num;
        Barr.push_back(num);
    }

    sort(Aarr.begin(), Aarr.end());
    sort(Barr.begin(), Barr.end());

    vector<int> result;

    for (size_t i = 0; i < Aarr.size(); i++)
    {        
        if (!binary_search(Barr.begin(), Barr.end(), Aarr[i]))
        {
            result.push_back(Aarr[i]);
        }
    }

    cout << result.size() << '\n';
    for (size_t i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }

    return 0;
}