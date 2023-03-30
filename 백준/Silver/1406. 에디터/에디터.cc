#include <iostream>
#include <string>
#include <stack>
#include <list>
#pragma warning(disable:4996)

using namespace std;

int main(void)
{
	list<char> li;	
	string str;

	getline(cin, str);

	for (char ch : str)
	{
		li.push_back(ch);
	}

	list<char>::iterator iter = li.end();

	int n;
	cin >> n;

	while (n--)
	{
		char input;

		cin >> input;

		if (input == 'L')
		{
			if (li.begin() != iter)
			{
				iter--;
			}
		}
		else if (input == 'D')
		{
			if (li.end() != iter)
			{
				iter++;
			}
		}
		else if (input == 'B')
		{
			if (!li.empty())
			{
				if (iter != li.begin())
				{
					iter--;
					iter = li.erase(iter);
					
				}
			}
		}
		else if (input == 'P')
		{
			char insertChar;

			cin >> insertChar;
	
			li.insert(iter, insertChar);
		}
	}

	while (!li.empty())
	{
		cout << li.front();
		li.pop_front();
	}

	return 0;
}