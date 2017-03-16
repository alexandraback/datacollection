#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#define N 111111
#define M 222222
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define INF 0x3f3f3f3f
#define mod 1000000007
#define LL long long
#define CLR(a,b) memset(a,b,sizeof(a))
#define FOE(i,a,b) for(int i=a;i<=b;++i)
#define FOD(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
int n,m,q,t,cs=0;
int dx[4]={0,0,-1,1},dy[4]={1,-1,0,0};
int a[N];
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        FOE(i,1,n)scanf("%d",&a[i]);
        int a1=0,a2=0;
        FOE(i,2,n)if(a[i]<a[i-1])a1+=a[i-1]-a[i];
        int df=0;
        FOE(i,2,n)if(a[i]<a[i-1])df=max(df,a[i-1]-a[i]);
        FOE(i,1,n-1)a2+=min(df,a[i]);
        printf("Case #%d: %d %d\n",++cs,a1,a2);
    }
	return 0;
}

