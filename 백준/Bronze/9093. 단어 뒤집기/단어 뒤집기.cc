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
		getline(cin, str); // 한줄 입력

		str += ' '; // 문자열 끝부분 공백 추가

		for (char ch : str)
		{
			if (ch == ' ')
			{
				while (!st.empty())
				{
					cout << st.top();
					st.pop();
				}

				cout << ch;
			}
			else
			{
				st.push(ch);
			}
		}
	}

	return 0;
}