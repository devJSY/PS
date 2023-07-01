#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int checkMaxLength(string& str)
{
	int MaxLength = 0;
	int check = 0;
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] == '-') check++;
		else check = 0;
		if (MaxLength < check) MaxLength = check;
	}

	return MaxLength;
}

void Recursion(string& str)
{
	int n = checkMaxLength(str);
	if (n == 1)
	{
		cout << str;
		return;
	}
	else
	{
		int num = str.size() / 3;
		string st1 = str.substr(0, num);
		string st2 = str.substr(num * 2, num);
		
		Recursion(st1);

		for (size_t i = 0; i < num; i++)
		{
			cout << ' ';
		}

		Recursion(st2);
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;
	int n = 0;

	while (cin >> n)
	{
		int size = pow(3, n);

		str.clear();
		str.append(size, '-');

		Recursion(str);
		cout << '\n';
	}

	return 0;
}