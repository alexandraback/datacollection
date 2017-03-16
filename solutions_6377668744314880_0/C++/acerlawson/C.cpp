#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>

#define msn(x) (memset((x),0,sizeof((x))))
#define msx(x) (memset((x),0x7f,sizeof((x))))
#define fuck(x) cerr << #x << " <- " << x << endl
#define acer cout<<"sb"<<endl
typedef long long ll;
using namespace std;
#define inf 0x3f3f3f3f
#define eps 1e-8
#define pi acos(-1.0)
int n;
const int maxn=20;
ll x[maxn],y[maxn];
int ans[maxn];

void work()
{
    memset(ans,0,sizeof(ans));
    if(n<4)return;
    for(int i=0;i<n;i++)ans[i]=n-3;
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            int a,b;
                a=b=0;
            for(int k=0;k<n;k++)
            {
                if((y[i]-y[j])*(x[k]-x[i])>(y[k]-y[i])*(x[i]-x[j]))a++;
                if((y[i]-y[j])*(x[k]-x[i])<(y[k]-y[i])*(x[i]-x[j]))b++;

            }
            ans[i]=min(ans[i],a);
            ans[j]=min(ans[j],a);
            ans[i]=min(ans[i],b);
            ans[j]=min(ans[j],b);
        }
    }
}
int main()
{
    int T;
    freopen("C-small-attempt1.in","r",stdin);
    freopen("C.out","w",stdout);
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d",&n);
        for(int i=0;i<n;i++)scanf("%lld%lld",&x[i],&y[i]);
        work();
        printf("Case #%d: \n",cas);
        for(int i=0;i<n;i++)printf("%d\n",ans[i]);
    }
    return 0;
}
