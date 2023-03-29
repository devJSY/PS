#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main(void)
{
	stack<char> st;
	int n;
	string str;
	
	cin >> n;
	cin.ignore(); // 입력 버퍼 초기화

	while (n--)
	{
		bool test = false;

		getline(cin, str); // 한줄 입력

		for (char ch : str)
		{
			if (ch == '(')
			{
				st.push(ch);
			}
			else
			{
				if (!st.empty())
				{
					st.pop();
				}
				else
				{
					cout << "NO" << "\n";
					test = true;
					break;
				}
			}
		}

		if (test == false)
		{
			if (st.empty())
			{
				cout << "YES" << "\n";
			}
			else
			{
				cout << "NO" << "\n";
			}
		}

		while (!st.empty()) st.pop();
	}

	return 0;
}