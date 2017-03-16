#include <iostream>
#include <stdio.h>

using namespace std;

const int MAXR = 16;
const int MAXC = 16;

int T, N, R, C;
int board[MAXR][MAXC];
int d[4][2] = { { 0, -1 }, { -1, 0 }, { 0, 1 }, { 1, 0 } };
int ans = 1 << 30;

bool IsInside(int x, int y)
{
    return x >= 0 && x < R && y >= 0 && y < C;
}

int GetHappiness()
{
    int h = 0;
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            for (int k = 0; k < 4; k++)
            {
                if (board[i][j] == 1 && IsInside(i + d[k][0], j + d[k][1]) && board[i + d[k][0]][j + d[k][1]] == 1)
                {
                    h++;
                }
            }
        }
    }

    return h / 2;
}

void Place(int r, int c, int curr)
{
    if (curr == 0)
    {
        ans = min(ans, GetHappiness());
        return;
    }

    if (R * C - 1 - (r * C + c) >= curr)
    {
        if (c == C - 1)
        {
            Place(r + 1, 0, curr);
        }
        else
        {
            Place(r, c + 1, curr);
        }
    }

    board[r][c] = 1;
    if (c == C - 1)
    {
        Place(r + 1, 0, curr - 1);
    }
    else
    {
        Place(r, c + 1, curr - 1);
    }
    board[r][c] = 0;
}

int main()
{
    //freopen("B-small-attempt0.in", "r", stdin);
    //freopen("B-small.out", "w", stdout);

    scanf("%d", &T);
    for (int t = 1; t <= T; t++)
    {
        scanf("%d %d %d", &R, &C, &N);

        ans = 1 << 30;
        Place(0, 0, N);

        printf("Case #%d: %d\n", t, ans);
    }
    return 0;
}

