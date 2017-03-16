#include<stdio.h>
#include<algorithm>
using namespace std;
int T;
int n;
int a[30];
int main()
{
    freopen("A-small-attempt0 (1).in","r",stdin);
    freopen("A-small.txt","w",stdout);
    int i,j,k;
    int p,q,r;
    int t,tt,ttt;
    int gr;
scanf("%d",&T);
for(int ii=1;ii<=T;ii++)
{
    scanf("%d",&n);
    for(i=0;i<30;i++)a[i]=0;
    for(i=0;i<n;i++)scanf("%d",&a[i]);
    printf("Case #%d: ",ii);
    while(1)
    {
        gr=0;
        ttt = -1;
        r=0;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0)
            {
                gr++;
                if(a[i]>ttt){ttt=a[i];p=i;}
            }
            r+=a[i];
        }
        tt = -1;
        for(i=0;i<n;i++)
        {
            if(a[i]!=0&&i!=p)
            {
                if(a[i]>tt){tt=a[i];q=i;}
            }
        }
        if(gr == 0)break;
        if(tt>ttt-1)k = tt;
        else k =  ttt-1;
        if((2*k)>(r-1))
        {
            a[p]--;
            a[q]--;
            printf("%c%c ",p+'A',q+'A');
        }
        else
        {
            a[p]--;
            printf("%c ",p+'A');
        }
    }

    printf("\n");
}


    return 0;
}
