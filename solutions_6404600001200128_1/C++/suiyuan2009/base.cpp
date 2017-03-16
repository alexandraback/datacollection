#include<cstdio>
#include<algorithm>
#include<string>
#include<cmath>
#include<cstring>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int maxn = 10005;

int n,a[maxn];

int main() {
    //freopen("in.cpp", "r", stdin);
    freopen("A-large.in","r",stdin);
    freopen("out", "w", stdout);
    int ncase=0;
    int T;
    scanf("%d",&T);
    while(T--) {
        scanf("%d",&n);
        int ret0=0,ret1=0;
        for(int i=1; i<=n; i++)scanf("%d",&a[i]);
        for(int i=2; i<=n; i++)
            if(a[i]<a[i-1]) {
                ret0+=a[i-1]-a[i];
                ret1=max(ret1,a[i-1]-a[i]);
            }
        int ret2=0;
        for(int i=1; i<n; i++) {
            if(a[i]<ret1)ret2+=a[i];
            else ret2+=ret1;
        }
        printf("Case #%d: %d %d\n",++ncase,ret0,ret2);
    }
    return 0;
}
