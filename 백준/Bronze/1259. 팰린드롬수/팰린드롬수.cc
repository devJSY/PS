#include <iostream>
#include <vector>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	vector<int> vec;
	int num;

	while (1)
	{
		cin >> num;
		if (num == 0)
			break;

		while (num != 0)
		{
			vec.push_back(num % 10);
			num /= 10;
		}

		bool flag = true;

		for (size_t i = 0; i < vec.size() / 2; i++)
		{
			if (vec[i] != vec[vec.size() - 1 - i])
			{
				flag = false;
				break;
			}
		}

		if(flag)
			cout << "yes" << endl;
		else
			cout << "no" << endl;

		vec.clear();
	}

	return 0;
}
