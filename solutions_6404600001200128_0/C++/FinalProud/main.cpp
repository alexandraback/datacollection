#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
#include <algorithm>
#include <vector>

#define lson l,mid,u << 1
#define rson mid + 1,r,u << 1 | 1
#define ls u << 1
#define rs u << 1 | 1

using namespace std;
typedef long long ll;
const double eps = 1e-9;
int a[1100];

int main()
{
    //freopen("in","r",stdin);
    //freopen("out","w",stdout);
    int T,n,cnt = 0;
    cin>>T;
    while(T--)
    {
       scanf("%d",&n);
       for(int i = 1; i <= n; i++)
            scanf("%d",a + i);
       ll x,y,maxn;
       x = y = maxn = 0;
       for(int i = 2; i <= n; i++)
       {
           if(a[i] < a[i - 1])
           {
               x += a[i - 1] - a[i];
               maxn = max((ll)(a[i - 1] - a[i]),maxn);
           }
       }
       for(int i = 1; i < n; i++)
       {
           y += min((ll)a[i],maxn);
       }
       printf("Case #%d: ",++cnt);
       cout<<x<<" "<<y<<endl;
    }
    return 0;
}
