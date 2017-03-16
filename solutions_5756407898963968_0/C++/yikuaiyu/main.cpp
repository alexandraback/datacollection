#include <cstdio>
using namespace std;

int a[4][4], b[4][4], m, n;

int isCross()
{
    int cnt = 0;
    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 4; ++j)
            if (a[m][i] == b[n][j])
                cnt++;
    return cnt;
}

int CrossNumber()
{
    for (int i = 0; i != 4; ++i)
        for (int j = 0; j != 4; ++j)
            if (a[m][i] == b[n][j])
                return a[m][i];
    return -1;
}

int main()
{
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
    int T;
    scanf("%d", &T);
    for (int Case = 1; Case <= T; ++Case)
    {
        scanf("%d", &m);
        for (int i = 0; i != 4; ++i)
            for (int j = 0; j != 4; ++j)
                scanf("%d", &a[i][j]);
        scanf("%d", &n);
        for (int i = 0; i != 4; ++i)
            for (int j = 0; j != 4; ++j)
                scanf("%d", &b[i][j]);

        m--, n--;
        printf("Case #%d: ", Case);
        int cnt = isCross();
        if (0 == cnt)
            printf("Volunteer cheated!\n");
        else if (1 == cnt)
            printf("%d\n", CrossNumber());
        else
            printf("Bad magician!\n");
    }
    return 0;
}
