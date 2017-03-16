#include <stdio.h>
#include <string.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
#define PI acos(-1.0)
#define M 1000005  //10^6
#define eps 1e-8
#define LL long long
#define moo 1000000007
#define INF -999999999
using namespace std;
int a[2000];
int main()
{
    freopen("1.in","r",stdin);
    freopen("1.out","w",stdout);
    int T;
    cin>>T;
    int dd=T;
    while(T--)
    {
        int n;
        cin>>n;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int ans1=0;
        int ma=0;
        for(int i=2;i<=n;i++)
        {
            //cout<<i<<ends<<ans1<<endl;
            if(a[i]<=a[i-1])
                ans1+=(a[i-1]-a[i]);
        }
        for(int i=1;i<=n-1;i++)
        {
            ma=max(a[i]-a[i+1],ma);
        }
        int ans2=0;
        for(int i=1;i<n;i++)
        {
            if(a[i]<=ma)
            {
                ans2+=a[i];
            }
            else
            {
                ans2+=ma;
            }
        }
        if(ans1==0) ans2=0;
        cout<<"Case #"<<dd-T<<": "<<ans1<<" "<<ans2<<endl;
    }
}
