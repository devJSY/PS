#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    int A, B, C;

    cin >> A >> B >> C;

    string str = to_string(A) + to_string(B);

    cout << A + B - C << '\n';
    cout << stoi(str) - C << '\n';

    return 0;
}
