#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int binarayTransform(string& s)
{
    int NumErazedZero = 0;
    
    string str = "";
    
    for(char c : s)
    {
        if(c == '0')
        {
            ++NumErazedZero;
        }
        else
        {
            str += c;
        }
    }
    
    s = str;    
    return NumErazedZero;
}

void ToBinaray(string& s)
{
    int Num = s.length();
    string str = "";
    
    while(1)
    {
        str += to_string(Num % 2);
        Num /= 2;
        
        if(0 == Num)
            break;
    }    
    
    reverse(str.begin(), str.end());
    
    s = str;
}

vector<int> solution(string s) {
    vector<int> answer;
    
    int NumZero = 0;
    int TransformCnt = 0;
    
    while(1)
    {
        if(s == "1")
            break;
        
        NumZero += binarayTransform(s);
        ToBinaray(s);
        ++TransformCnt;
    }
    
    answer.push_back(TransformCnt);
    answer.push_back(NumZero);

    
    return answer;
}