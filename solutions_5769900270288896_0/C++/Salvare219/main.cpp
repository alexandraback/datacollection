#include<bits/stdc++.h>
using namespace std;


int v[50][50];
int main()
{
    //freopen("1.txt","r",stdin);
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int t,ti=1;scanf("%d",&t);
    while(t--)
    {
        int n,m,k;
        scanf("%d%d%d",&n,&m,&k);
        int tot=n*m;
        int lim=1<<tot,ans=1000000;
        for(int i=0;i<lim;i++)
        {
            memset(v,0,sizeof(v));
            int cnt=0;
            for(int j=0;j<tot;j++)
                if((1<<j)&i)cnt++,v[j/m][j%m]=1;
            if(cnt==k)
            {
                int f=0;
                for(int j=0;j<n;j++)
                    for(int z=0;z<m;z++)
                        if(v[j][z])
                        {
                            if(j!=0&&v[j-1][z])f++;
                            if(z!=0&&v[j][z-1])f++;
                        }
                ans=min(f,ans);
            }
        }
        printf("Case #%d: %d\n",ti++,ans);
    }
    return 0;
}
