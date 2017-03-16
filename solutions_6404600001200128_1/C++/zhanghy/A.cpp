#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

typedef long long LL;

const int maxn = 1010;
const int INF = 1000000000;

int T,N,M;
int a[maxn];

bool cal(LL x) {
    LL w = 0;
    //cout<<x<<endl;
    for (int i = 2;i <= N; i++) {
        w = a[i-1]-x;
      //  cout<<w<<endl;
        if (w > a[i]) return false;
    }
    return true;
}

int main() {
        freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.in","r",stdin);
        freopen("/Users/zhanghanyuan/Documents/codejam/round1A/1.out","w",stdout);
        scanf("%d",&T);
        for (int kase = 1;kase <= T; kase++) {
            scanf("%d",&N);
            for (int i = 1;i <= N; i++) scanf("%d",&a[i]);
            int ans1 = 0,ans2 = 0;
            for (int i = 1;i <= N-1; i++) {
                if (a[i] > a[i+1]) ans1 += a[i]-a[i+1];
            }
            int l = 0,r = INF;
            while (l < r) {
                int mid = (l+r)>>1;
                if (cal(mid)) r = mid;
                else l = mid+1;
            }
            //cout<<"l: "<<l<<endl;
            for (int i = 1;i <= N-1; i++) {
                if (a[i] < l) ans2 += a[i];
                else ans2 += l;
            }
            printf("Case #%d: %d %d\n",kase,ans1,ans2);
        }
        return 0;

 }
