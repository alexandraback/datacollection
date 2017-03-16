#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
using namespace std;
#define NUM 105
#define LEN 105

struct block
{
    char ch;
    int num;
} b[NUM][LEN];

int T, N;
char a[NUM][LEN];
int len[NUM];
bool ok;
int ans;

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

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    scanf("%d", &T);
    for (int x = 1; x <= T; x++)
    {
        scanf("%d%s%s", &N, a[0], a[1]);
        work(0);
        work(1);
        ok = true;
        ans = 0;
        if (len[0] != len[1])
            ok = false;
        else
        {
            for (int i = 0; i < len[0]; i++)
            {
                if (b[0][i].ch != b[1][i].ch)
                {
                    ok = false;
                    break;
                }
                ans += abs(b[0][i].num - b[1][i].num);
            }
        }
        printf("Case #%d: ", x);
        (ok) ? printf("%d\n", ans) : puts("Fegla Won");
    }
    return 0;
}
