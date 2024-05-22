#include <string>
#include <iostream>
using namespace std;

bool solution(string s)
{
    bool answer = true;
    
    int Pcnt = 0;
    int Ycnt = 0;
    
    for(char c : s)
    {
        if(c == 'p' || c == 'P')
            ++Pcnt;
        
        if(c == 'y' || c == 'Y')
            ++Ycnt;
    }
    
    if(Pcnt != Ycnt)
        answer = false;

    return answer;
}