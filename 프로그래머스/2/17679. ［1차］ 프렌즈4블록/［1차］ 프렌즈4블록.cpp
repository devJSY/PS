#include <string>
#include <vector>

using namespace std;

vector<vector<char>> Board;
vector<vector<bool>> Delete;
int result = 0;
int M = 0;
int N = 0;

bool CheckBlock()
{
    bool bDirty = false;

    for (int i = 0; i < Board.size() - 1; ++i)
    {
        for (int j = 0; j < Board[i].size() - 1; ++j)
        {
            if (Board[i][j] == '*')
                continue;

            char LT = Board[i][j];
            char LB = Board[i][j + 1];
            char RT = Board[i + 1][j];
            char RB = Board[i + 1][j + 1];

            // 2x2 가 같은 모양의 블록 인경우
            // if (0 == (LT + LB - RT + RB))
            if (LT == LB && RT == RB && LT == RT)
            {
                Delete[i][j] = true;
                Delete[i][j + 1] = true;
                Delete[i + 1][j] = true;
                Delete[i + 1][j + 1] = true;

                bDirty = true;
            }
        }
    }

    return bDirty;
}

void DeleteBlock()
{
    for (int i = 0; i < Delete.size(); ++i)
    {
        for (int j = 0; j < Delete[i].size(); ++j)
        {
            if (Delete[i][j])
            {
                Board[i][j] = '*';
                Delete[i][j] = false;
                ++result;
            }
        }
    }
}

void MoveBlock()
{
    // 좌 하단에서 부터 시작
    for (int j = 0; j < N; ++j)
    {
        for (int i = M - 1; i >= 0; --i)
        {
            if (Board[i][j] != '*')
                continue;

            int tempI = i;

            // 문자가 있는지 찾는다
            while (tempI >= 0 && Board[tempI][j] == '*')
            {
                --tempI;
            }

            if (tempI < 0)
                continue;

            // Swap
            char TempChar = Board[i][j];
            Board[i][j] = Board[tempI][j];
            Board[tempI][j] = TempChar;
        }
    }
}

int solution(int m, int n, vector<string> board)
{
    M = m;
    N = n;

    Board.resize(m);
    for (int i = 0; i < Board.size(); ++i)
    {
        Board[i].resize(n);
    }

    for (int i = 0; i < Board.size(); ++i)
    {
        for (int j = 0; j < board.size(); ++j)
        {
            Board[i][j] = board[i][j];
        }
    }

    Delete.resize(m);
    for (int i = 0; i < Delete.size(); ++i)
    {
        Delete[i].resize(n);
    }

    while (1)
    {
        if (!CheckBlock())
        {
            break;
        }

        DeleteBlock();
        MoveBlock();
    }

    return result;
}
