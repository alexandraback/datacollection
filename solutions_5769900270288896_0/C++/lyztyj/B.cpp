#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
int n,m,k;
int w[16][16];
int calc(int i,int j)
{
    if(!w[i][j])return 0;
    int u=0;
    if(i>0)u+=w[i-1][j];
    if(j>0)u+=w[i][j-1];
    if(i+1<n)u+=w[i+1][j];
    if(j+1<m)u+=w[i][j+1];
    return u;
}
void Solve()
{
    int T,cnt=0,ans;
    scanf("%d",&T);
    while(T--)
    {
        ans=1000000;
        scanf("%d%d%d",&n,&m,&k);
        for(int stu=0;stu<(1<<(n*m));stu++)
        {
            int u=0,t=stu;
            while(t)
            {
                if(t%2)u++;
                t/=2;
            }
            if(u!=k)continue;
            t=stu;
            //cout<<t<<endl;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                {
                    if(t%2==1)w[i][j]=1;
                    else w[i][j]=0;
                    t/=2;
                }
            int now=0;
            for(int i=0;i<n;i++)
                for(int j=0;j<m;j++)
                    now+=calc(i,j);
            now/=2;
            if(ans>now)ans=now;
        }
        printf("Case #%d: %d\n",++cnt,ans);
    }
}
int main()
{
    freopen("B-small-attempt0.in","r",stdin);
    freopen("B-small-attempt0.out","w",stdout);
    Solve();
    return 0;
}
