#include <cstdio>

using namespace std;

int v[20][20];

int brut(int n,int m,int k)
{
    int nr=n*m,lim=1<<nr,sol=100;
    for(int i=1;i<=n+1;i++)
        for(int j=1;j<=m+1;j++) v[i][j]=0;
    for(int i=0;i<lim;i++)
    {
        int cnt=0,s=0;
        for(int j=0;j<nr;j++)
            if(i&(1<<j)) {v[j/m+1][j%m+1]=1;cnt++;}
            else v[j/m+1][j%m+1]=0;
        if(cnt!=k) continue;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
                if(v[i][j])
                {
                    if(v[i+1][j]) s++;
                    if(v[i][j+1]) s++;
                }
        if(s<sol) sol=s;
    }
    return sol;
}

int main()
{
    freopen("file.in", "r", stdin);
    freopen("file.out", "w", stdout);
    int test;
    scanf("%d",&test);
    for(int t=1;t<=test;t++)
    {
        int n,m,k,s,sol=0;
        scanf("%d%d%d",&n,&m,&k);
        int n1=n,m1=m,k1=k;
        if(n*m<=16) sol=brut(n,m,k);
        else
        {
            s=((n+1)/2)*((m+1)/2)+(n/2)*(m/2);
            if(k<=s) sol=0;
            else
            {
                int x=(n/2+m/2)*2;
                k-=s;
                if(n==1 || m==1)
                {
                    if(n%2==0 || m%2==0) {sol++;k--;}
                    if(k) sol+=k*2;
                }
                else
                {
                    if(n%2==0 || m%2==0)
                    {
                        if(k<=2) {sol=k*2;k=0;}
                        else {sol=4;k-=2;}
                    }
                    if(n%2 && m%2==0) x-=3;
                    else if(n%2==0 && m%2) x-=3;
                    else if(n%2==0 && m%2==0) x-=4;
                    if(k<=x) sol+=k*3;
                    else
                    {
                        sol+=x*3;
                        k-=x;
                        sol+=k*4;
                    }
                }
            }
        }
        printf("Case #%d: %d\n",t,sol);
    }
    return 0;
}
