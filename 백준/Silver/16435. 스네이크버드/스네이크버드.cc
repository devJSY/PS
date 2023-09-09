#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() 
{
    ios_base::sync_with_stdio(0); 
    cin.tie(0);

 

    int n = 0;
    int l = 0;

    cin >> n >> l;

    vector<int>v(n);

    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++) {
        if (v[i] <= l)
            l += 1;
    }

    cout << l;

	return 0;
}
