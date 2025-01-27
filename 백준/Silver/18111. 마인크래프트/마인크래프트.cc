#include <iostream>

using namespace std;

int N, M, B;
int Board[500][500];

int main()
{
    ios_base::sync_with_stdio(NULL);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> B;

    for (int y = 0; y < N; ++y)
    {
        for (int x = 0; x < M; ++x)
        {
            cin >> Board[y][x];
        }
    }

    int MinTime = 987654321;
    int ret = 987654321;

    for (int CurHeight = 0; CurHeight <= 256; ++CurHeight)
    {
        int Minus = 0;
        int Plus = 0;

        for (int y = 0; y < N; ++y)
        {
            for (int x = 0; x < M; ++x)
            {
                int Step = CurHeight - Board[y][x];

                if (Step >= 0)
                {
                    Plus += Step;
                }
                else
                {
                    Minus += -Step;
                }
            }
        }

        if ((B + Minus - Plus) >= 0 && MinTime >= (Minus * 2 + Plus))
        {
            MinTime = Minus * 2 + Plus;
            ret = CurHeight;
        }
    }

    cout << MinTime << " " << ret << '\n';

    return 0;
}
