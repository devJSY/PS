#include <iostream>
#include <cstring>

using namespace std;

int main() 
{
    char arr[101] = {};
    cin >> arr;
    bool flag = true;
    int length = strlen(arr);

    for (int i = 0; i < length; i++)
    {
        if (arr[i] != arr[length - 1 - i])
        {
            flag = false;
            break;
        }
    }

    cout << flag << endl;

    return 0;
}
