#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> asc = { 1,2,3,4,5,6,7,8 };
	vector<int> des = { 8,7,6,5,4,3,2,1 };

	vector<int> input;

	input.resize(8);

	for (size_t i = 0; i < 8; i++)
	{
		cin >> input[i];
	}

	if (equal(begin(input), end(input), begin(asc), end(asc)))
		cout << "ascending" << endl;
	else if (equal(begin(input), end(input), begin(des), end(des)))
		cout << "descending" << endl;
	else
		cout << "mixed" << endl;

	return 0;
}
