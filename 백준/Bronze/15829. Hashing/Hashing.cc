#include <iostream>
#include <cmath>

using namespace std;

#define Mod 1234567891

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int L;
	long long hash = 0;
	string str;
	char a;
	
	cin >> L;
	cin >> str;

	long long r = 1;

	for (size_t i = 0; i < L; i++)
	{
		a = str[i];
		hash = (hash + (a - 96) * r) % Mod;
		r = (r * 31) % Mod;
	}

	cout << hash << endl;

	return 0;
}
