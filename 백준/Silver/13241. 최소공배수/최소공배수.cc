#include <iostream>

using namespace std;

int gcd(int a, int b)
{
    while (b > 0)
    {
        int tmp = a;
        a = b;
        b = tmp % b;
    }
    return a;
}

int main()
{
	long long a = 0;
	long long b = 0;

	cin >> a >> b;
	cout << a * b / gcd(a, b) << '\n';

	return 0;
}