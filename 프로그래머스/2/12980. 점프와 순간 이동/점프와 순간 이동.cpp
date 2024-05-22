#include <iostream>
using namespace std;

int solution(int n)
{
    int result = 0;
    while(n >= 1)
    {
        if(n % 2 == 0)
        {
            n /= 2;
        }
        else
        {
            --n;
            ++result;
        }        
    }
    
    return result;
}