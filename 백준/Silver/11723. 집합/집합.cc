#include <iostream>

using namespace std;

bool arr[50];

void add(int x)
{
    arr[x] = true;
}

void remove(int x)
{
    arr[x] = false;
}

void check(int x)
{
    cout << arr[x] << '\n';
}

void toggle(int x)
{
    arr[x] = !arr[x];
}

void all()
{
    for (int i = 1; i <= 20; ++i)
    {
        arr[i] = true;
    }
}

void empty()
{
    for (int i = 1; i <= 20; ++i)
    {
        arr[i] = false;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int M;
    cin >> M;

    while (M--)
    {
        string str;
        int x;
        cin >> str;
        if (!(str == "all" || str == "empty"))
        {
            cin >> x;
        }

        if (str == "add")
        {
            add(x);
        }
        else if (str == "remove")
        {
            remove(x);
        }
        else if (str == "check")
        {
            check(x);
        }
        else if (str == "toggle")
        {
            toggle(x);
        }
        else if (str == "all")
        {
            all();
        }
        else if (str == "empty")
        {
            empty();
        }
    }

    return 0;
}
