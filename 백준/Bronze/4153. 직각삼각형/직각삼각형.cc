#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec(3);

	while (1)
	{
		cin >> vec[0] >> vec[1] >> vec[2];

		if (vec[0] == 0 && vec[1] == 0 && vec[2] == 0)
			break;

		sort(begin(vec), end(vec));

		if (pow(vec[2], 2) == pow(vec[0], 2) + pow(vec[1], 2))
			cout << "right" << endl;
		else
			cout << "wrong" << endl;
	}

	return 0;
}
