#include<cstdio>
#include<algorithm>
using namespace std;
int Q,QQ,n,k,m,rez,a[200][200];
void backt(int t,int x,int y)
{
    if(t<=k)
    {
        int i=x;
        for(int j=y+1;j<=m;j++)
            if(a[i][j]==0)
            {
                a[i][j]=1;
                backt(t+1,i,j);
                a[i][j]=0;
            }
        for(int i=x+1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                if(a[i][j]==0)
                {
                    a[i][j]=1;
                    backt(t+1,i,j);
                    a[i][j]=0;
                }
            }
    }
    else
    {
        int cate=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(a[i][j]==1)
                {
                    if(a[i+1][j]==1)cate++;
                    if(a[i-1][j]==1)cate++;
                    if(a[i][j+1]==1)cate++;
                    if(a[i][j-1]==1)cate++;
                }
        cate/=2;
        if(rez>cate)rez=cate;
    }
}
int main()
{
    freopen("input","r",stdin);
    freopen("output","w",stdout);
    scanf("%d",&Q);
    while(QQ<Q)
    {
        QQ++;
        printf("Case #%d: ",QQ);
        scanf("%d %d %d",&n,&m,&k);
        if(n>m)swap(n,m);
        rez=10000;
        if(n==1)
        {
            k=k-m/2-m%2;
            if(k<=0)rez=0;
            else rez=k*2-1+m%2;
        }
        else if(n==2)
        {
            k-=m;
            if(k<=0)rez=0;
            else
            {
                if(k==1)rez=2;
                else rez=3*k-2;
            }
        }
        else if(n>2)
        {
            if(m%2==0&&k<=n*m/2)rez=0;
            else if(m%2==1&&k<=n*(m/2)+n/2+n%2)rez=0;
            else
            {
                a[1][1]=1;
                backt(2,1,1);
                a[1][1]=0;
            }
        }
        printf("%d\n",rez);
    }
    return 0;
}
