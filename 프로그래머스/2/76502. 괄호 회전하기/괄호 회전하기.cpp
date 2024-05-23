#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
     int answer = 0;

    int len = s.length();

    for (int i = 0; i < len; ++i)
    {
        string str = s.substr(i, len);
        str += s.substr(0, i);

        bool bCorrect = true;
        stack<char> Stack;
        for (char ch : str)
        {
            if (!Stack.empty())
            {
                char TopChar = Stack.top();
                if (TopChar == '[' && ch == ']' || TopChar == '{' && ch == '}' || TopChar == '(' && ch == ')')
                {
                    Stack.pop();
                }
                else
                {
                    Stack.push(ch);
                }
            }
            else
            {
                Stack.push(ch);
            }
        }

        bCorrect = Stack.empty();

        answer += bCorrect;
    }

    return answer;
}