#include <bits/stdc++.h>
#define LL long long

using namespace std;

const int maxn = 1000 + 10;

using namespace std;
struct node
{
    int x,num;
    bool operator < (const node &A)const
    {
        return num<A.num;
    }
};
node a[30];
void work()
{
    int n,sum= 0;
    scanf("%d",&n);
    for (int i=1;i<=n;i++) {scanf("%d",&a[i].num); a[i].x=i-1; sum+=a[i].num;}
    sort(a+1,a+n+1);
    while(sum){
        if (a[n-1].num > (sum-1)/2)
        {
            printf(" %c%c",'A'+(a[n-1].x),'A'+(a[n].x));
            a[n].num--;
            a[n-1].num--;
            if (a[n].num == 0) n--;
            if (a[n].num == 0) n--;
            sum-=2;
        }
        else
        {
            printf(" %c",'A'+(a[n].x));
            a[n].num--;
            if (a[n].num == 0) n--;
            sum-=1;
        }
    }
    printf("\n");
}

int main()
{
    freopen("in.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int T, cas = 0 ;
    scanf("%d",&T);
    while(T--)
    {
        printf("Case #%d:",++cas);
        work();
    }
    return 0;
}
