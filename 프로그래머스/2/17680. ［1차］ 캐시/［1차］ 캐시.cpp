#include <string>
#include <vector>
#include <list>

using namespace std;

list<string> Cache;

bool IsChachHit(string str)
{
    list<string>::iterator it = Cache.begin();

    while (it != Cache.end())
    {
        if (*it == str)
        {
            Cache.erase(it);
            Cache.push_back(str);

            return true;
        }

        ++it;
    }

    return false;
}

string ToLower(string str)
{
    for (int i = 0; i < str.size(); ++i)
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
        {
            str[i] += 32;
        }
    }

    return str;
}

int solution(int cacheSize, vector<string> cities)
{
    int answer = 0;

    for (string str : cities)
    {
        str = ToLower(str);

        if (IsChachHit(str))
        {
            answer += 1;
        }
        else
        {
            answer += 5;

            Cache.push_back(str);

            if (Cache.size() > cacheSize)
            {
                Cache.pop_front();
            }
        }
    }

    return answer;
}
