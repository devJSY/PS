#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(string s) {
    string answer = "";
    
    vector<int> vecNums;
    string temp;
    for(int i = 0; i < s.size(); ++i)
    {
        if(s[i] == ' ')
        {
            vecNums.push_back(stoi(temp));
            temp = "";
            continue;
        }
        
        if(s[i] == '-')
        {
           temp = '-';
        }
        else
        {
            temp += s[i];
        }
    }
    
    if(!temp.empty())
    {
        vecNums.push_back(stoi(temp));
    }
    
    sort(vecNums.begin(), vecNums.end());
    
    answer = to_string(vecNums.front());
    answer += ' ';
    answer += to_string(vecNums.back());
    
    return answer;
}