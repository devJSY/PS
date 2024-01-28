#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int answer = 0;
    int num = 0;
    bool minus = false;

    for (int i = 0; i <= s.size(); i++) {
        if (s[i] == '+' || s[i] == '-' || s[i] == '\0') {
            if (minus) {
                answer -= num;
            } else {
                answer += num;
            }

            if (s[i] == '-') {
                minus = true;
            }

            num = 0;
        } else {
            num = num * 10 + (s[i] - '0');
        }
    }

    cout << answer << endl;

    return 0;
}