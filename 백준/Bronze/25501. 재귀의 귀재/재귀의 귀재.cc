#include <iostream>
#include <cstring>

int num = 0;

int recursion(const char* s, int l, int r) {
	num++;
	if (l >= r) return 1;
	else if (s[l] != s[r]) return 0;
	else return recursion(s, l + 1, r - 1);
}

int isPalindrome(const char* s) {
	return recursion(s, 0, strlen(s) - 1);
}

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	string str;

	int n = 0;
	cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		cin >> str;
		cout << isPalindrome(str.c_str()) << " " << num << '\n';
		num = 0;
	}

	return 0;
}