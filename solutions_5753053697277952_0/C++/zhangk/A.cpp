#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

struct ptype
{
    char c;
    int cnt;
    bool operator < (const ptype &b)const
    {
        return cnt > b.cnt;
    }
};

int T, n, kase = 0, m;
ptype p[30];

int main()
{
    freopen("A-small-attempt0.in", "r", stdin);
    freopen("A-small-attempt0.out", "w", stdout);
    cin >> T;
    while (T--)
    {
        cin >> n;
        int i;
        m = 0;
        for (i = 1; i <= n; i++)
        {
            cin >> p[i].cnt;
            p[i].c = 'A' + i - 1;
            m += p[i].cnt;
        }
        printf("Case #%d:", ++kase);
        if (m & 1)
        {
            printf(" A");
            p[1].cnt--;
            m--;
        }
        while (m > 0)
        {
            sort(p + 1, p + n + 1);
            p[1].cnt--;
            p[2].cnt--;
            m -= 2;
            printf(" %c%c", p[1].c, p[2].c);
        }
        printf("\n");
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
