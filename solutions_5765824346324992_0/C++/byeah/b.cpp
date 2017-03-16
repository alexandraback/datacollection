#include<cstdio>
#include<algorithm>
int n,m;
int d[1010];

long long cal(long long t)
{
    long long cnt=0;
    for(int i=0;i<n;i++)
        cnt+=t/d[i]+1;
    return cnt;
}

int slot[1010];

int find()
{
    long long l=0,r=100000;r*=1000000000;
    long long t;
    do{
        long long k=(l+r)>>1;
        if (cal(k)>=m)
        {
            t=k;
            r=k-1;
        }
        else
            l=k+1;
    }while(l<=r);
    long long cur = 0;
    slot[0]=0;
    for(int i=0;i<n;i++)
    {
        cur+=(t+d[i]-1)/d[i];
        if (t%d[i]==0)
            slot[++slot[0]]=i;
    }
//    printf("%d %d\n",t,slot[0]);
    return slot[m-cur]+1;
}

int main()
{
    freopen("bs.in","r",stdin);
    freopen("bs.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++)
    {
        scanf("%d%d",&n,&m);
        for(int i=0;i<n;i++)
            scanf("%d",d+i);
        int ans=find();
        printf("Case #%d: %d\n",ii,ans);
    }
    return 0;
}
    
            
            
        
