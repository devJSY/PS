#include <iostream>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n = 0;

	cin >> n;

	long long result = 0;

	for (size_t i = 0; i < n; i++)
	{
		char ch;
		cin >> ch;

		result += (ch - 96) * pow(31, i);
	}

	cout << result << endl;

	return 0;
}
