#include<cstdio>
#include<cstring>
#include<iostream>

using namespace std;
int num[1005];
int main()
{
    freopen("A-small-attempt0.in","r",stdin);
    freopen("A-small-attempt0.out","w",stdout);
    int t;
    scanf("%d",&t);
    int c=t;
    while(t--)
    {
        int n;scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&num[i]);
        int res1=0,res2=0;
        int v=0;
        for(int i=1;i<n;i++)
            if(num[i]<num[i-1])
            {
                v=max(num[i-1]-num[i],v);
                res1+=num[i-1]-num[i];
            }
        for(int i=0;i<n-1;i++)
        {
            res2+=min(num[i],v);
        }
        printf("Case #%d: %d %d\n",c-t,res1,res2);
    }
    return 0;
}
