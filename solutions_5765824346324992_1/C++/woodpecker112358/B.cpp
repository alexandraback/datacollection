#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<cctype>
#include<cassert>
#include<vector>
#include<set>
#include<map>
#include<list>
#include<deque>
#include<utility>
#include<queue>
#include<stack>
#include<ctime>
#include<algorithm>
#define SZ 1005
using namespace std;
int a[SZ];
int main()
{
    freopen("B-large.in","r",stdin);
    freopen("Bout.txt","w",stdout);
    int T,n,b;
    cin>>T;
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&b,&n);
        for(int i=0;i<b;i++)
            scanf("%d",&a[i]);
        long long lo=0,hi=1000000000000000LL,mid,cnt;
        while(lo<hi)
        {
            mid=(lo+hi)/2+1;
            //cout<<lo<<" "<<hi<<" "<<mid<<endl;
            cnt=0;
            for(int i=0;i<b;i++)
            {
                cnt+=mid/a[i];
                if(mid%a[i])
                    cnt++;
            }
            //cout<<cnt<<endl;
            if(cnt>n-1)
                hi=mid-1;
            else
                lo=mid;
        }
        //cout<<lo<<endl;
        int ans=0;
        cnt=0;
        for(int i=0;i<b;i++)
        {
            cnt+=lo/a[i];
            if(lo%a[i])
                cnt++;
        }
        long long ext=n-cnt;
        //cout<<ext<<endl;
        for(int i=0;i<b;i++)
            if(lo%a[i]==0)
            {
                ext--;
                if(ext==0)
                {
                    ans=i+1;
                    break;
                }
            }
        printf("Case #%d: %d\n",cas,ans);
    }
    return 0;
}


