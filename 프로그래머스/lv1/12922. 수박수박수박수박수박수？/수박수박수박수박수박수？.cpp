#include <string>
#include <vector>
#include <iostream>

using namespace std;

string solution(int n) {
    string answer = "";
    bool Trig = true;
    int i;
    
    for(i = 0; i <n; ++i)
    {
        if (Trig) answer += "수";
        else answer += "박";
        
         Trig = !Trig;
    }
    
    
    return answer;
}