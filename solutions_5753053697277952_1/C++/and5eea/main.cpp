#include <cstdio>
#include <algorithm>
using namespace std;
int l,i,nrt,n,s,ok;
struct andreea
{
    int nr;
    char lit;
}a[30];
bool cmp(andreea a, andreea b)
{
    if(a.nr<b.nr)return 1;
    return 0;
}
int main()
{
    freopen("A.in","r",stdin);
    freopen("A.out","w",stdout);
    scanf("%d",&nrt);
    for(l=1;l<=nrt;l++)
    {
        scanf("%d",&n);
        printf("Case #%d: ",l);
        for(i=1;i<=n;i++)
        {
            scanf("%d",&a[i].nr);
            a[i].lit=char(i+'A'-1);
        }
        while(1)
        {
            sort(a+1,a+n+1,cmp);
            s=0;
            for(i=1;i<=n;i++)
                s=s+a[i].nr;
            if(s==0)break;
            if(s==1)
            {
                printf("%c ",a[n].lit);
                break;
            }
            ok=0;
            for(i=1;i<=n-2;i++)
            if(a[i].nr>(s-2)/2){ok=1;break;}
            if(ok==0)
            {
                if(a[n].nr>=a[n-1].nr+2)
                {
                    printf("%c%c ",a[n].lit,a[n].lit);
                    a[n].nr--;
                    a[n].nr--;
                }
                else
                {

                    printf("%c%c ",a[n].lit,a[n-1].lit);
                    a[n].nr--;
                    a[n-1].nr--;
                }
            }
            else
            {
                printf("%c ",a[n].lit);
                a[n].nr--;
            }
        }
        printf("\n");
    }
    return 0;
}
