#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define NUM 105
#define LEN 105
#define INF 1000000000

struct block
{
    char ch;
    int num;
} b[NUM][LEN];

int T, N;
char a[NUM][LEN];
int len[NUM];
bool ok;
int ans, final;

void work(int x)
{
    int i, j;
    for (i = j = 0; a[x][i]; i++)
        if (j && a[x][i] == b[x][j - 1].ch)
            b[x][j - 1].num++;
        else
        {
            b[x][j].ch = a[x][i];
            b[x][j++].num = 1;
        }
    len[x] = j;
}

void work2(int x, int y)
{
    if (len[x] != len[y])
        ok = false;
    else
    {
        for (int i = 0; i < len[x]; i++)
            if (b[x][i].ch != b[y][i].ch)
            {
                ok = false;
                break;
            }
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d", &N);
        for (int i = 0; i < N; i++)
        {
            scanf("%s", a[i]);
            work(i);
        }
        ok = true;
        for (int i = 1; i < N; i++)
            work2(0, i);
        printf("Case #%d: ", x);
        if (ok)
        {
            final = 0;
            for (int i = 0; i < len[0]; i++)
            {
                int mm = 1;
                for (int j = 0; j < N; j++)
                    if (b[j][i].num > mm)
                        mm = b[j][i].num;
                int ans = INF;
                for (int j = 1; j <= mm; j++)
                {
                    int tmp = 0;
                    for (int k = 0; k < N; k++)
                        tmp += abs(j - b[k][i].num);
                    if (tmp < ans)
                        ans = tmp;
                }
                final += ans;
            }
            printf("%d\n", final);
        }
        else
            puts("Fegla Won");
    }
    return 0;
}
