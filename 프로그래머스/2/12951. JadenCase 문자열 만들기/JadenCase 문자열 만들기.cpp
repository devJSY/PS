#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    string answer = "";
    
    for(char c : s)
    {
        if(c >= 'A' && c <= 'Z')
        {
            answer += c + 32;
        }
        else 
        {
            answer += c;
        }
    }
    
    bool bReset = true;
    
    for(int i = 0; i < answer.size(); ++i)
    {
        if(bReset)
        {
            if(answer[i] >= 'a' && answer[i] <= 'z')
            {
                answer[i] = answer[i] - 32;
            }
            
            bReset = false;
        }
        
        if(answer[i] == ' ')
        {
            bReset = true;
        }
    }
    
    
    return answer;
}