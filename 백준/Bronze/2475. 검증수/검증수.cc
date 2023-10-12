#include <iostream>
#include<cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int sum = 0;

	int num = 0;

	for (size_t i = 0; i < 5; i++)
	{
		cin >> num;
		sum += pow(num, 2);
	}

	cout << sum % 10 << endl;

	return 0;
}
