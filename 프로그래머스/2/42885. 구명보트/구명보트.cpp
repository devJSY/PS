#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    sort(people.begin(), people.end());
    
    int lp = 0;
    int rp = people.size() - 1;
    
    while(lp <= rp)
    {
        if(people[lp] + people[rp] <= limit)
        {
            ++lp;
            --rp;
        }
        else
        {
            --rp;
        }
        
        ++answer;
    }
    
    return answer;
}