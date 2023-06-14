#include <iostream>
using namespace std;

int main()
{
	int loop = 0;

	cin >> loop;

	int n = 4;
	int line = 2;
	int center = 1;
	int ractangle = 1;
	int dot = 3;
	while (loop > 0)
	{
		n = n + (dot * line) - center;
		ractangle *= 2;
		line *= 2;
		dot += ractangle;
		center *= 4;

		--loop;
	}

	cout << n << endl;

    return 0;
}
