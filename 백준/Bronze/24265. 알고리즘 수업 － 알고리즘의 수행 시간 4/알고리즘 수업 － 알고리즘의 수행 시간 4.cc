#include <iostream>

using namespace std;

int main()
{
    long n = 0;
    cin >> n;
    long long sum = 0;

    for (int i = 1; i < n; i++)
    {
        sum += i;
    }

    cout << sum << endl << 2 << endl;

    return 0;
}
