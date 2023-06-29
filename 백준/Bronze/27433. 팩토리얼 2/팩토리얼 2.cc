#include <iostream>

using namespace std;

long long int factorial(int n)
{
	if (n <= 1) return 1;
	return factorial(n - 1) * n;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;
	cin >> n;
	
	cout << factorial(n);
	
	return 0;
}