#include <iostream>

using namespace std;

bool IsPrime(int N)
{
    if (N == 1)
        return 0;

    for (int i = 2; i * i <= N; ++i)
    {
        if (N % i == 0)
            return 0;
    }

    return 1;
}

int main()
{
    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; ++i)
    {
        int input;
        cin >> input;
        if (IsPrime(input))
            count++;
    }

    cout << count;

    return 0;
}
