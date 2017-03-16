#include<cstdio>
#include<algorithm>
int n;
int d[1010];

int main()
{
    freopen("as.in","r",stdin);
    freopen("as.out","w",stdout);
    int tt;
    scanf("%d",&tt);
    for(int ii=1;ii<=tt;ii++)
    {
        scanf("%d",&n);
        int ans1=0,ans2=0,ma=0;
        for(int i=0;i<n;i++)
            scanf("%d",d+i);
        for(int i=1;i<n;i++)
        {
            if (d[i]<d[i-1]){
                ans1+=d[i-1]-d[i];
                if (d[i-1]-d[i]>ma)
                    ma=d[i-1]-d[i];
            }
        }
//        int rate = (ma+9)/10;
        for(int i=1;i<n;i++)
            ans2+=std::min(d[i-1],ma);
        printf("Case #%d: %d %d\n",ii,ans1,ans2);
    }
    return 0;
}
    
            
            
        
