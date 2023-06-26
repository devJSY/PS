#include <iostream>

#define SIZE 300000

using namespace std;

int prime[SIZE] = {1,1};

int main()
{
    int n = 0;

    // 에라토스테네스의 체 
    for (int i = 2; i < SIZE; i++)
    {
        for (int j = i + i; j < SIZE; j += i)
        {
            prime[j] = 1;
        }
    }

    while (1)
    {
        cin >> n;
        if (n == 0) break;
        else
        {
            int num = 0;

            for (int i = n + 1; i <= 2 * n; i++)
            {
                if (prime[i] == 0) num++;
            }

            cout << num << '\n';
        }
    }
  
    return 0;
}