#include <string>
#include <unordered_map>

using namespace std;

bool IsCharacter(char& ch)
{
    if ('A' <= ch && ch <= 'Z')
    {
        ch += 32; // 소문자로 변환
        return true;
    }
    else if ('a' <= ch && ch <= 'z')
    {
        return true;
    }

    return false;
}

int solution(string str1, string str2)
{
    unordered_map<string, int> MapA;
    unordered_map<string, int> MapB;

    for (int i = 0; i < str1.size() - 1; ++i)
    {
        if (IsCharacter(str1[i]) && IsCharacter(str1[i + 1]))
        {
            string str = str1.substr(i, 2);
            ++MapA[str];
        }
    }

    for (int i = 0; i < str2.size() - 1; ++i)
    {
        if (IsCharacter(str2[i]) && IsCharacter(str2[i + 1]))
        {
            string str = str2.substr(i, 2);
            ++MapB[str];
        }
    }

    int intersection = 0;
    int Union = 0;

    for (const auto& elemA : MapA)
    {
        if (0 != MapB.count(elemA.first))
        {
            intersection += min(MapB[elemA.first], elemA.second);
            Union += max(MapB[elemA.first], elemA.second);
        }
        // 겹치는게 없었다.
        else
        {
            Union += elemA.second;
        }
    }

    // 겹치지 않는 부분
    for (const auto& elemB : MapB)
    {
        if (0 == MapA.count(elemB.first))
        {
            Union += elemB.second;
        }
    }

    // 둘다 공집합인 경우
    if (0 == intersection && 0 == Union)
    {
        intersection = 1;
        Union = 1;
    }

    int answer = ((float)intersection / (float)Union) * 65536;
    return answer;
}
