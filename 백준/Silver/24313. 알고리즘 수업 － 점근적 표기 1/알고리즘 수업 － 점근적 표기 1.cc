#include <iostream>

using namespace std;

int main() 
{
	int a1 = 0;
	int a2 = 0;
	int c = 0;
	int n = 0;

	cin >> a1 >> a2 >> c >> n;

	if (a1 * n + a2 <= c * n && c * n >= a1 * n ) cout << 1 << endl;
	else cout << 0 << endl;
}
