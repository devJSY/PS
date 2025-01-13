#include <iostream>
#include <string>
#include <deque>

using namespace std;

// 성공여부 반환
bool ProcessCommand(const string& Command, deque<int>& dQ, bool& bRev)
{
    for (const char& ch : Command)
    {
        if (ch == 'R')
        {
            bRev = !bRev;
        }
        else
        {
            // 비어있는데 P연산이 들어온 경우
            if (dQ.empty())
                return false;

            if (bRev)
            {
                dQ.pop_back();
            }
            else
            {
                dQ.pop_front();
            }
        }
    }

    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int T;
    cin >> T;

    while (T--)
    {
        string Command;
        int N;
        string arr;
        deque<int> dQ;

        cin >> Command >> N >> arr;

        // 예외처리
        if (arr != "[]")
        {
            // 배열 입력 변환
            int num = 0;
            for (const char& ch : arr)
            {
                if (ch == '[')
                    continue;

                if (ch == ',' || ch == ']')
                {
                    dQ.push_back(num);
                    num = 0;
                }
                else
                {
                    num *= 10;
                    num += ch - '0';
                }
            }
        }

        bool bRev = false;
        if (!ProcessCommand(Command, dQ, bRev))
        {
            cout << "error" << '\n';
            continue;
        }

        // 출력
        cout << "[";
        while (dQ.size() > 1)
        {
            if (bRev)
            {
                cout << dQ.back();
                dQ.pop_back();
            }
            else
            {
                cout << dQ.front();
                dQ.pop_front();
            }
            cout << ",";
        }

        if (!dQ.empty())
        {
            cout << dQ.front();
        }

        cout << "]" << '\n';
    }

    return 0;
}
