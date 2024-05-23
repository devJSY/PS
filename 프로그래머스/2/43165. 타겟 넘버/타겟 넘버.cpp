#include <string>
#include <vector>

using namespace std;

int result = 0;

void DFS(int L,int sum, const vector<int>& numbers, int target)
{
    if(L == numbers.size())
    {
        if(sum == target)
            ++result;
        return;
    }
    
    DFS(L +1, sum + numbers[L], numbers, target);    
    DFS(L +1, sum - numbers[L], numbers, target);
}

int solution(vector<int> numbers, int target) {
    DFS(0, 0, numbers, target);
    return result;
}