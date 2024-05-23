#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    
    set<string> Set;
    string prevWord = words[0];
    Set.insert(prevWord);

    for (int i = 1; i < words.size(); ++i)
    {
        auto iter = Set.insert(words[i]);
        if (words[i].front() != prevWord.back() || !iter.second)
        {
            answer.push_back(i % n + 1);
            answer.push_back(i / n + 1);
            break;
        }

        prevWord = words[i];
    }
    
    if(answer.empty())
    {
        answer.push_back(0);
        answer.push_back(0);
    }
       
    return answer;
}