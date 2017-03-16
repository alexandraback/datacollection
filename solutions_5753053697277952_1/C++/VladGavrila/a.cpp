#include <cstdio>

using namespace std;

#define maxn 100010

int t, n;
int v[maxn];

int main()
{
    freopen("A-large.in", "r", stdin);
    freopen("data.out", "w", stdout);

    scanf("%d", &t);

    for(int test=1; test<=t; ++test)
    {
        scanf("%d", &n);

        int mx1=0, p1=0, mx2=0, p2=0;

        for(int i=1; i<=n; ++i)
        {
            scanf("%d", &v[i]);
            if(v[i]>mx1)
            {
                mx2=mx1;
                p2=p1;
                mx1=v[i];
                p1=i;
            }
            else
            if(v[i]>mx2)
            {
                mx2=v[i];
                p2=i;
            }
        }

        printf("Case #%d:", test);

        while(v[p1]>v[p2])
        {
            printf(" %c", char('A'+p1-1));
            --v[p1];
        }

        for(int i=1; i<=n; ++i)
            if(i!=p1 && i!=p2)
                for(int j=1; j<=v[i]; ++j)
                    printf(" %c", char('A'+i-1));

        for(int i=1; i<=v[p2]; ++i)
            printf(" %c%c", char('A'+p1-1), char('A'+p2-1));

        printf("\n");
    }

    return 0;
}
