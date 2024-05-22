#include <iostream>

using namespace std;
int solution(int n)
{
    int answer = 0;
    
    while(1)
    {
        answer += n %10;
        n /= 10;
        
        if(0 == n)
        {
            break;
        }
    }

    return answer;
}