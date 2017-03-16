#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
int n,cate,s;
struct partid
{
    int v;
    char c;
}a[40];
bool cmp(partid a, partid b)
{
    if(a.v==b.v)return a.c<b.c;
    return a.v>b.v;
}
int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    int Q;
    scanf("%d\n",&Q);
    for(int test=1;test<=Q;test++)
    {
        printf("Case #%d: ",test);

        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i].v);
            s+=a[i].v;
            a[i].c='A'+i-1;
        }
        sort(a+1,a+n+1,cmp);
        while(s)
        {
            if(a[1].v!=a[2].v&&a[2].v*2<=s-2)
            {
                a[1].v-=2;
                printf("%c%c ",a[1].c,a[1].c);
                s-=2;
            }
            else if(a[1].v!=a[2].v)
            {

                a[1].v--;
                printf("%c ",a[1].c);
                s--;
            }
            else if(a[3].v*2<=s-2)
            {
                a[1].v--;
                a[2].v--;
                printf("%c%c ",a[1].c,a[2].c);
                s-=2;
            }
            else
            {
                a[1].v--;
                printf("%c ",a[1].c);
                s--;
            }
            sort(a+1,a+n+1,cmp);
        }
        printf("\n");
    }
    return 0;
}
