#include <iostream>

using namespace std;

int gcd(int a, int b) 
{
	while (b != 0)
	{
		int temp = a % b;
		a = b;
		b = temp;
	}
	
	return a;
}

int main()
{
	int a = 0;
	int b = 0;
	int c = 0;
	int d = 0;

	cin >> a >> b >> c >> d;

	int e = a * d + b * c; 
	int f = b * d;

	int min = gcd(e, f);
	e /= min;
	f /= min;
	cout << e << ' ' << f << '\n';;
	return 0;

	return 0;
}