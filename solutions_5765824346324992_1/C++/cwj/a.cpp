#include <algorithm>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <string>
#include <vector>
using namespace std;

int T,B;
long long N,M[1005];

long long cal(long long ti,int id)
{
    long long cnt=0;
    for(int i=1;i<=B;i++)
    {
        cnt+=(ti/M[i]);
        cnt++;
        if(((ti%M[i])==0)&&(i>id))
        {
            cnt--;
        }
    }
    return cnt;
}

int main()
{
    freopen("B-large.in","r",stdin);
    freopen("B-large.out","w",stdout);
    cin>>T;
    for(int ca=1;ca<=T;ca++)
    {
        cin>>B>>N;
        for(int i=1;i<=B;i++) cin>>M[i];
        int ans=0;
        for(int i=1;i<=B;i++)
        {
            bool flag=false;
            long long left=-1,right=N+1;
            while((left+1)<right)
            {
                long long mid=(left+right)/2;
                long long cwj=cal(mid*M[i],i);
                if(cwj==N){
                    flag=true;
                    break;
                } else {
                    if(cwj>N) right=mid;
                    else left=mid;
                }
            }
            if(flag)
            {
                ans=i;
                break;
            }
        }
        cout<<"Case #"<<ca<<": "<<ans<<endl;
    }
    return 0;
}
