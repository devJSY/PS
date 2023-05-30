#include <vector>
#include <set>
using namespace std;



int solution(vector<int> nums)
{
    set<int> s;
    int n = nums.size() / 2;
    
    for(int i = 0; i < nums.size(); ++i)
    {
        s.insert(nums[i]);        
    }    
    
    int answer = 0;
    
    if(s.size() < n)
    {
        answer = s.size();
    }
    else
    {
        answer = n;
    }        
   
    return answer;
}