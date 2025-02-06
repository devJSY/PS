#include <iostream>

using namespace std;

int A, B, C;

long long solve(int exp)
{
    if (exp == 0)
        return 1;

    long long temp = solve(exp / 2);
    temp = temp * temp % C;

    if (exp % 2 == 0)
        return temp;
    else
        return temp * A % C;
}

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> A >> B >> C;

    cout << solve(B);

    return 0;
}
