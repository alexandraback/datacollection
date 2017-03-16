#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<iostream>
#include<queue>
#include<stack>
#include<vector>
#include<map>
#include<set>
#include<string>
using namespace std;
#define INF 0x3f3f3f3f
#define eps 1e-8
#define mod 100007
int a[1005];
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    scanf("%d",&t);
    int cas=1;
    while(t--)
    {
        int b,n;
        scanf("%d%d",&b,&n);
        long long l=0,r=0;
        for(int i=0;i<b;i++)
        {
            scanf("%d",a+i);
            r=max(r,(long long)a[i]);
        }
        r=r*(long long)n;
        int fin=-1;
        while(l<=r)
        {
            long long mid=(l+r)/2;
            long long temp=0;
            int num=0;
            for(int i=0;i<b;i++)
            {
                temp+=mid/a[i];
                if(mid%a[i]==0)  num++;
                else temp++;
            }
            if(temp>=(long long)n)
            {
                r=mid-1;
                continue;
            }
            else if(temp+(long long)num<(long long)n)
            {
                l=mid+1;
                continue;
            }
            else
            {
                for(int i=0;i<b;i++)
                {
                    if(mid%(long long)a[i]==0) temp++;
                    if(temp==(long long)n)
                    {
                        fin=i+1;
                        break;
                    }
                }
                break;
            }
        }
        printf("Case #%d: %d\n",cas++,fin);
    }
}
