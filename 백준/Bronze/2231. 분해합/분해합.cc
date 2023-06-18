#include <iostream>

using namespace std;

int n = 0;

bool Decomposition(int num)
{
	int sum = num;

	while (num > 0)
	{
		sum += num % 10;
		num /= 10;
	}

	if (sum == n) return true;
	else return false;
}

int main() 
{
    cin >> n;

	for (size_t i = 0; i < n; i++)
	{
		if (Decomposition(i))
		{
			cout << i << endl;
			return 0; 
		}
	}

	cout << 0 << endl;
  
    return 0;
}
