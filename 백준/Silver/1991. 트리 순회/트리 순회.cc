#include <bits/stdc++.h>

using namespace std;

int N;
char lc[30];
char rc[30];

void preorder(int _Idx)
{
    if (0 == _Idx)
        return;

    cout << char(_Idx + 'A' - 1);
    preorder(lc[_Idx]);
    preorder(rc[_Idx]);
}

void inorder(int _Idx)
{
    if (0 == _Idx)
        return;

    inorder(lc[_Idx]);
    cout << char(_Idx + 'A' - 1);
    inorder(rc[_Idx]);
}

void postorder(int _Idx)
{
    if (0 == _Idx)
        return;

    postorder(lc[_Idx]);
    postorder(rc[_Idx]);
    cout << char(_Idx + 'A' - 1);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;

    for (size_t i = 0; i < N; i++)
    {
        char p, l, r;

        cin >> p >> l >> r;
        if (l != '.')
            lc[p - 'A' + 1] = l - 'A' + 1;
        if (r != '.')
            rc[p - 'A' + 1] = r - 'A' + 1;
    }

    preorder(1);
    cout << '\n';
    inorder(1);
    cout << '\n';
    postorder(1);

    return 0;
}