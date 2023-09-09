#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

    string str;

    vector<string> vec;

    cin >> str;

    for (size_t i = 0; i < str.length(); i++)
    {
        vec.push_back(str.substr(i, str.length()));
    }

    sort(vec.begin(), vec.end());

    for (size_t i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }


	return 0;
}
