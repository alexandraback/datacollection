#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int a[20];
int main()
{
    freopen("in.in","r",stdin);
    freopen("out.txt","w",stdout);
    int t,Case=0;
    scanf("%d",&t);
    while(t--)
    {
        memset(a,0,sizeof(a));
        int n,x;
        scanf("%d",&n);
        for(int i=1;i<=4;++i)
            for(int j=0;j<4;++j)
            {
                scanf("%d",&x);
                if(i==n)++a[x];
            }
        scanf("%d",&n);
        for(int i=1;i<=4;++i)
            for(int j=0;j<4;++j)
            {
                scanf("%d",&x);
                if(i==n)++a[x];
            }
        int ans=0,f=0;
        for(int i=1;i<=16;++i)
            if(a[i]==2)ans=i,++f;
        printf("Case #%d: ",++Case);
        if(f==0)printf("Volunteer cheated!\n");
        else if(f==1)printf("%d\n",ans);
        else printf("Bad magician!\n");
    }
    return 0;
}
